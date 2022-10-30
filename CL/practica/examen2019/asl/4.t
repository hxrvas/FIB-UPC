function main
  vars
    before 1
    a 10
    after 1
    i 1
  endvars

     %1 = 199
     before = %1
     %2 = 299
     after = %2
     %3 = 0
     %4 = 5
     a[%3] = %4
     %5 = 1
     %6 = 3
     a[%5] = %6
     %7 = 2
     %8 = 8
     a[%7] = %8
     %9 = 3
     %10 = 9
     a[%9] = %10
     %11 = 4
     %12 = 7
     a[%11] = %12
     %13 = 5
     %14 = 3
     a[%13] = %14
     %15 = 6
     %16 = 4
     a[%15] = %16
     %17 = 7
     %18 = 6
     a[%17] = %18
     %19 = 8
     %20 = 5
     a[%19] = %20
     %21 = 9
     %22 = 8
     a[%21] = %22
     %23 = 0
     i = %23
  label while1 :
     %24 = 10
     %25 = i < %24
     ifFalse %25 goto endwhile1
     writes "a["
     writei i
     writes "]="
     %26 = a[i]
     writei %26
     writes "\n"
     %27 = 1
     %28 = i + %27
     i = %28
     goto while1
  label endwhile1 :
     writes "a) a.max="
     %32 = 0
     %30 = a[%32]
     %32 = 1
     %34 = 1
     %33 = 10
  label while2 :
     %31 = %32 < %33
     ifFalse %31 goto endwhile2
     %35 = a[%32]
     %36 = %30 < %35
     ifFalse %36 goto endif1
     %30 = %35
  label endif1 :
     %32 = %34 + %32
     goto while2
  label endwhile2 :
     writei %30
     writes "\n"
     %37 = 0
     %38 = 0
     %39 = a[%38]
     %40 = 5
     %41 = %39 * %40
     a[%37] = %41
     writes "b) a.max="
     %45 = 0
     %43 = a[%45]
     %45 = 1
     %47 = 1
     %46 = 10
  label while3 :
     %44 = %45 < %46
     ifFalse %44 goto endwhile3
     %48 = a[%45]
     %49 = %43 < %48
     ifFalse %49 goto endif2
     %43 = %48
  label endif2 :
     %45 = %47 + %45
     goto while3
  label endwhile3 :
     writei %43
     writes "\n"
     %50 = 9
     %51 = 9
     %52 = a[%51]
     %53 = 0
     %54 = a[%53]
     %55 = %52 + %54
     a[%50] = %55
     writes "c) a.max="
     %59 = 0
     %57 = a[%59]
     %59 = 1
     %61 = 1
     %60 = 10
  label while4 :
     %58 = %59 < %60
     ifFalse %58 goto endwhile4
     %62 = a[%59]
     %63 = %57 < %62
     ifFalse %63 goto endif3
     %57 = %62
  label endif3 :
     %59 = %61 + %59
     goto while4
  label endwhile4 :
     writei %57
     writes "\n"
     return
endfunction


