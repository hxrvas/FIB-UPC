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
     s = %2
  label while1 :
     %3 = 10
     %4 = i < %3
     ifFalse %4 goto endwhile1
     %5 = x
     %6 = %5[i]
     %7 = y
     %8 = %7[i]
     %9 = %6 * %8
     %10 = s + %9
     s = %10
     %11 = 1
     %12 = i + %11
     i = %12
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
     a[i] = %5
     %6 = 9
     %7 = %6 - i
     %8 = 1
     %9 = i + %8
     %10 = 2
     %11 = %9 * %10
     b[%7] = %11
     %12 = 1
     %13 = i + %12
     i = %13
     goto while1
  label endwhile1 :
     writes "dotprod manual = "
     pushparam 
     %14 = &a
     pushparam %14
     %15 = &b
     pushparam %15
     call dotprod
     popparam 
     popparam 
     popparam %16
     writei %16
     writes "\n"
     writes "dotprod operador = "
     %17 = 0
     %21 = 0
     %23 = 1
     %22 = 10
  label while2 :
     %20 = %21 < %22
     ifFalse %20 goto endwhile2
     %25 = b[%21]
     %24 = a[%21]
     %26 = %24 * %25
     %17 = %17 + %26
     %21 = %23 + %21
     goto while2
  label endwhile2 :
     writei %17
     writes "\n"
     return
endfunction


