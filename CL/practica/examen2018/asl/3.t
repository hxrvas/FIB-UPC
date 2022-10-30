function i_dotprod
  params
    _result
    x
    y
  endparams

     %2 = x
     %3 = y
     %1 = 0
     %5 = 0
     %7 = 1
     %6 = 10
  label while1 :
     %4 = %5 < %6
     ifFalse %4 goto endwhile1
     %9 = %3[%5]
     %8 = %2[%5]
     %10 = %8 * %9
     %1 = %1 + %10
     %5 = %7 + %5
     goto while1
  label endwhile1 :
     _result = %1
     return
     return
endfunction

function f_dotprod
  params
    _result
    x
    y
  endparams

     %2 = x
     %3 = y
     %1 = 0
     %5 = 0
     %7 = 1
     %6 = 10
  label while1 :
     %4 = %5 < %6
     ifFalse %4 goto endwhile1
     %9 = %3[%5]
     %8 = %2[%5]
     %10 = %8 *. %9
     %1 = %1 +. %10
     %5 = %7 + %5
     goto while1
  label endwhile1 :
     _result = %1
     return
     return
endfunction

function i_readvec
  params
    x
  endparams

  vars
    i 1
  endvars

     %1 = 0
     i = %1
  label while1 :
     %2 = 10
     %3 = i < %2
     ifFalse %3 goto endwhile1
     %4 = x
     readi %5
     %4[i] = %5
     %6 = 1
     %7 = i + %6
     i = %7
     goto while1
  label endwhile1 :
     return
endfunction

function f_readvec
  params
    x
  endparams

  vars
    i 1
  endvars

     %1 = 0
     i = %1
  label while1 :
     %2 = 10
     %3 = i < %2
     ifFalse %3 goto endwhile1
     %4 = x
     readf %5
     %4[i] = %5
     %6 = 1
     %7 = i + %6
     i = %7
     goto while1
  label endwhile1 :
     return
endfunction

function main
  vars
    a 10
    b 10
    c 10
    d 10
  endvars

     %1 = &a
     pushparam %1
     call i_readvec
     popparam 
     %2 = &b
     pushparam %2
     call i_readvec
     popparam 
     %3 = &c
     pushparam %3
     call f_readvec
     popparam 
     %4 = &d
     pushparam %4
     call f_readvec
     popparam 
     writes "dotprod int funcio = "
     pushparam 
     %5 = &a
     pushparam %5
     %6 = &b
     pushparam %6
     call i_dotprod
     popparam 
     popparam 
     popparam %7
     writei %7
     writes "\n"
     writes "dotprod float funcio = "
     pushparam 
     %8 = &c
     pushparam %8
     %9 = &d
     pushparam %9
     call f_dotprod
     popparam 
     popparam 
     popparam %10
     writef %10
     writes "\n"
     writes "dotprod int local = "
     %11 = 0
     %15 = 0
     %17 = 1
     %16 = 10
  label while1 :
     %14 = %15 < %16
     ifFalse %14 goto endwhile1
     %19 = b[%15]
     %18 = a[%15]
     %20 = %18 * %19
     %11 = %11 + %20
     %15 = %17 + %15
     goto while1
  label endwhile1 :
     writei %11
     writes "\n"
     writes "dotprod float local = "
     %21 = 0
     %25 = 0
     %27 = 1
     %26 = 10
  label while2 :
     %24 = %25 < %26
     ifFalse %24 goto endwhile2
     %29 = d[%25]
     %28 = c[%25]
     %30 = %28 *. %29
     %21 = %21 +. %30
     %25 = %27 + %25
     goto while2
  label endwhile2 :
     writef %21
     writes "\n"
     return
endfunction


