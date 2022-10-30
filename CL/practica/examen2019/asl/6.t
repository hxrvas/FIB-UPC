function f
  params
    _result
    a
    b
  endparams

     %1 = a
     %4 = 0
     %2 = %1[%4]
     %4 = 1
     %6 = 1
     %5 = 3
  label while1 :
     %3 = %4 < %5
     ifFalse %3 goto endwhile1
     %7 = %1[%4]
     %8 = %2 < %7
     ifFalse %8 goto endif1
     %2 = %7
  label endif1 :
     %4 = %6 + %4
     goto while1
  label endwhile1 :
     %9 = b + %2
     _result = %9
     return
     return
endfunction

function g
  params
    _result
    a
    b
  endparams

     %1 = b
     %4 = 0
     %2 = %1[%4]
     %4 = 1
     %6 = 1
     %5 = 3
  label while1 :
     %3 = %4 < %5
     ifFalse %3 goto endwhile1
     %7 = %1[%4]
     %8 = %2 < %7
     ifFalse %8 goto endif1
     %2 = %7
  label endif1 :
     %4 = %6 + %4
     goto while1
  label endwhile1 :
     %9 = %2 < a
     ifFalse %9 goto else3
     %10 = b
     %13 = 0
     %11 = %10[%13]
     %13 = 1
     %15 = 1
     %14 = 3
  label while2 :
     %12 = %13 < %14
     ifFalse %12 goto endwhile2
     %16 = %10[%13]
     %17 = %11 < %16
     ifFalse %17 goto endif2
     %11 = %16
  label endif2 :
     %13 = %15 + %13
     goto while2
  label endwhile2 :
     _result = %11
     return
     goto endif3
  label else3 :
     %18 = b
     %19 = 2
     %20 = %18[%19]
     _result = %20
     return
  label endif3 :
     return
endfunction

function main
  vars
    a 3
    b 3
  endvars

   %1 = 0
   %2 = 7
   a[%1] = %2
   %3 = 1
   %4 = 3
   a[%3] = %4
   %5 = 2
   %6 = 14
   a[%5] = %6
   %7 = 0
   %8 = 'o'
   b[%7] = %8
   %9 = 1
   %10 = 'c'
   b[%9] = %10
   %11 = 2
   %12 = 'a'
   b[%11] = %12
   writes "a) f(a, 23)="
   pushparam 
   %13 = &a
   pushparam %13
   %14 = 23
   pushparam %14
   call f
   popparam 
   popparam 
   popparam %16
   writei %16
   writes "\n"
   writes "b) g('z', b)="
   pushparam 
   %17 = 'z'
   pushparam %17
   %18 = &b
   pushparam %18
   call g
   popparam 
   popparam 
   popparam %20
   writec %20
   writes "\n"
   writes "c) g('e', b)="
   pushparam 
   %21 = 'e'
   pushparam %21
   %22 = &b
   pushparam %22
   call g
   popparam 
   popparam 
   popparam %24
   writec %24
   writes "\n"
   return
endfunction


