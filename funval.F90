! funval()  -- 
! function for the extension of the displacement function in the wave equation outside the interval 
! [0,L] --> [-2L,3L] facilitating the use of the d'Alembert formula for a 
! full time period -- t in [0,2L/c]
!
!  we assume,
!   o FUNCHOICE(x) works for x in [0,L] 
!   o zz (1st param to funval()) in [-2L,3L]
!   o LL (2nd param to funval()) equals L

! this version avoids an earlier bug related to F90 pass-by-reference
! by copying the input param to a work variable ww and mapping the latter...

        double precision function funval(zz,LL) !map zz to [0,L] and call base fn
        implicit none
        
        double precision            :: zz, LL, bot, top, ww
        double precision, external  :: gaussian, sine, cubic

        bot=-2.0d0*LL
        top= 3.0d0*LL

! let's avoid actually changing zz -- because of pass-by-reference !!
        ww = zz

        if (ww < bot) then 
          ww = bot
        end if

        if (ww > top) then 
          ww = top
        end if

        if (EXTEND .eq. 0) then
          funval = FUNCHOICE(ww)
          return
        end if

!!both these clauses map zz to [0,2L] (else it's there already)
!! ... based on the knowledge that the extended f(zz) has period 
!! 2L in zz -- we also assume zz arrives in [-2L,3L] and first map 
!! anything outside [0,2L] back to it...
  if (ww < 0.0d0) then
    ww = ww+2.0d0*LL
  end if
  if (ww > 2.0d0*LL) then
    ww = ww-2.0d0*LL
  end if

!!if zz in [L,2L], map back to [0,L] and flip parity,
  if (ww > LL) then
    ww = 2.0d0*LL-ww     !!zz in [0,L]
    funval = -FUNCHOICE(ww)
    return 
  end if
!!zz in [0,L]
  funval = FUNCHOICE(ww)
  return 

  end function funval
