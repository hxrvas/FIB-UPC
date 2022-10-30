function dotprod
  params
    _result
    x
    y
  endparams

  vars
    i 1
    s 1
  endvars

     %1 = 0
     i = %1
     %2 = 0
     %3 = float %2
     s = %3
  label while1 :
     %4 = 10
     %5 = i < %4
     ifFalse %5 goto endwhile1
     %6 = x
     %7 = %6[i]
     %8 = y
     %9 = %8[i]
     %10 = %7 *. %9
     %12 = s +. %10
     s = %12
     %14 = 1
     %15 = i + %14
     i = %15
     goto while1
  label endwhile1 :
     _result = s
     return
     return
endfunction

function main
  vars
    a 10
    b 10
    i 1
  endvars

     %1 = 0
     i = %1
  label while1 :
     %2 = 10
     %3 = i < %2
     ifFalse %3 goto endwhile1
     %4 = 1
     %5 = i + %4
     %6 = 2.5
     %8 = float %5
     %7 = %8 /. %6
     a[i] = %7
     %9 = 9
     %10 = %9 - i
     %11 = 1
     %12 = i + %11
     %13 = 0.7
     %15 = float %12
     %14 = %15 *. %13
     b[%10] = %14
     %16 = 1
     %17 = i + %16
     i = %17
     goto while1
  label endwhile1 :
     writes "dotprod manual = "
     pushparam 
     %18 = &a
     pushparam %18
     %19 = &b
     pushparam %19
     call dotprod
     popparam 
     popparam 
     popparam %20
     writef %20
     writes "\n"
     writes "dotprod operador = "
     %21 = 0
     %25 = 0
     %27 = 1
     %26 = 10
  label while2 :
     %24 = %25 < %26
     ifFalse %24 goto endwhile2
     %29 = b[%25]
     %28 = a[%25]
     %30 = %28 *. %29
     %21 = %21 +. %30
     %25 = %27 + %25
     goto while2
  label endwhile2 :
     writef %21
     writes "\n"
     return
endfunction


