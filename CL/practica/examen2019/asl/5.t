function init
  params
    aC
  endparams

   %1 = aC
   %2 = 0
   %3 = 5.4
   %4 = -. %3
   %1[%2] = %4
   %5 = aC
   %6 = 1
   %7 = 3.7
   %8 = -. %7
   %5[%6] = %8
   %9 = aC
   %10 = 2
   %11 = 8.2
   %12 = -. %11
   %9[%10] = %12
   %13 = aC
   %14 = 3
   %15 = 5.1
   %16 = -. %15
   %13[%14] = %16
   %17 = aC
   %18 = 4
   %19 = 7.9
   %20 = -. %19
   %17[%18] = %20
   %21 = aC
   %22 = 5
   %23 = 10
   %24 = - %23
   %25 = float %24
   %21[%22] = %25
   return
endfunction

function main
  vars
    a 6
    b 3
    i 1
  endvars

     %1 = &a
     pushparam %1
     call init
     popparam 
     %2 = 0
     %3 = 'h'
     b[%2] = %3
     %4 = 1
     %5 = 'b'
     b[%4] = %5
     %6 = 2
     %7 = 'o'
     b[%6] = %7
     %8 = 0
     i = %8
  label while1 :
     %9 = 6
     %10 = i < %9
     ifFalse %10 goto endwhile1
     writes "a["
     writei i
     writes "]="
     %11 = a[i]
     writef %11
     writes "\n"
     %12 = 1
     %13 = i + %12
     i = %13
     goto while1
  label endwhile1 :
     %14 = 1000
     i = %14
  label while2 :
     %15 = 1003
     %16 = i < %15
     ifFalse %16 goto endwhile2
     writes "b["
     %17 = 1000
     %18 = i - %17
     writei %18
     writes "]="
     %19 = 1000
     %20 = i - %19
     %21 = b[%20]
     writec %21
     writes "\n"
     %22 = 1
     %23 = i + %22
     i = %23
     goto while2
  label endwhile2 :
     writes "a) a.max="
     %27 = 0
     %25 = a[%27]
     %27 = 1
     %29 = 1
     %28 = 6
  label while3 :
     %26 = %27 < %28
     ifFalse %26 goto endwhile3
     %30 = a[%27]
     %31 = %25 <. %30
     ifFalse %31 goto endif1
     %25 = %30
  label endif1 :
     %27 = %29 + %27
     goto while3
  label endwhile3 :
     writef %25
     writes "\n"
     writes "b) b.max="
     %35 = 0
     %33 = b[%35]
     %35 = 1
     %37 = 1
     %36 = 3
  label while4 :
     %34 = %35 < %36
     ifFalse %34 goto endwhile4
     %38 = b[%35]
     %39 = %33 < %38
     ifFalse %39 goto endif2
     %33 = %38
  label endif2 :
     %35 = %37 + %35
     goto while4
  label endwhile4 :
     writec %33
     writes "\n"
     return
endfunction


