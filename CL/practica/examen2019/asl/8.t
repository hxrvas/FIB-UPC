function main
  vars
    a 10
    i 1
    x 1
  endvars

     %1 = 5
     i = %1
     %2 = 2
     %3 = 2222
     a[%2] = %3
  label while1 :
     %4 = 5
     %5 = - %4
     %6 = %5 < i
     ifFalse %6 goto endwhile1
     %7 = 0
     %8 = i < %7
     ifFalse %8 goto endIf1
     %99 = 'R'
     writec %99
     %99 = 'u'
     writec %99
     %99 = 'n'
     writec %99
     %99 = 't'
     writec %99
     %99 = 'i'
     writec %99
     %99 = 'm'
     writec %99
     %99 = 'e'
     writec %99
     %99 = ' '
     writec %99
     %99 = 'E'
     writec %99
     %99 = 'r'
     writec %99
     %99 = 'r'
     writec %99
     %99 = 'o'
     writec %99
     %99 = 'r'
     writec %99
     %99 = ':'
     writec %99
     %99 = ' '
     writec %99
     %99 = 'L'
     writec %99
     %99 = 'i'
     writec %99
     %99 = 'n'
     writec %99
     %99 = 'e'
     writec %99
     %99 = ' '
     writec %99
     %99 = '7'
     writec %99
     %99 = ':'
     writec %99
     %99 = '8'
     writec %99
     %99 = '.'
     writec %99
     %99 = ' '
     writec %99
     %99 = 'A'
     writec %99
     %99 = 'c'
     writec %99
     %99 = 'c'
     writec %99
     %99 = 'e'
     writec %99
     %99 = 's'
     writec %99
     %99 = 's'
     writec %99
     %99 = ' '
     writec %99
     %99 = 'o'
     writec %99
     %99 = 'u'
     writec %99
     %99 = 't'
     writec %99
     %99 = ' '
     writec %99
     %99 = 'o'
     writec %99
     %99 = 'f'
     writec %99
     %99 = ' '
     writec %99
     %99 = 'r'
     writec %99
     %99 = 'a'
     writec %99
     %99 = 'n'
     writec %99
     %99 = 'g'
     writec %99
     %99 = 'e'
     writec %99
     %99 = ':'
     writec %99
     %99 = ' '
     writec %99
     %99 = 'a'
     writec %99
     %99 = '['
     writec %99
     %99 = 'i'
     writec %99
     %99 = ']'
     writec %99
     writeln
     halt
  label endIf1 :
     %9 = a[i]
     x = %9
     writes "a["
     writei i
     writes "] ok"
     %10 = 2
     %11 = i == %10
     ifFalse %11 goto endif3
     %12 = 0
     %13 = i < %12
     ifFalse %13 goto endIf2
     %99 = 'R'
     writec %99
     %99 = 'u'
     writec %99
     %99 = 'n'
     writec %99
     %99 = 't'
     writec %99
     %99 = 'i'
     writec %99
     %99 = 'm'
     writec %99
     %99 = 'e'
     writec %99
     %99 = ' '
     writec %99
     %99 = 'E'
     writec %99
     %99 = 'r'
     writec %99
     %99 = 'r'
     writec %99
     %99 = 'o'
     writec %99
     %99 = 'r'
     writec %99
     %99 = ':'
     writec %99
     %99 = ' '
     writec %99
     %99 = 'L'
     writec %99
     %99 = 'i'
     writec %99
     %99 = 'n'
     writec %99
     %99 = 'e'
     writec %99
     %99 = ' '
     writec %99
     %99 = '1'
     writec %99
     %99 = '0'
     writec %99
     %99 = ':'
     writec %99
     %99 = '2'
     writec %99
     %99 = '5'
     writec %99
     %99 = '.'
     writec %99
     %99 = ' '
     writec %99
     %99 = 'A'
     writec %99
     %99 = 'c'
     writec %99
     %99 = 'c'
     writec %99
     %99 = 'e'
     writec %99
     %99 = 's'
     writec %99
     %99 = 's'
     writec %99
     %99 = ' '
     writec %99
     %99 = 'o'
     writec %99
     %99 = 'u'
     writec %99
     %99 = 't'
     writec %99
     %99 = ' '
     writec %99
     %99 = 'o'
     writec %99
     %99 = 'f'
     writec %99
     %99 = ' '
     writec %99
     %99 = 'r'
     writec %99
     %99 = 'a'
     writec %99
     %99 = 'n'
     writec %99
     %99 = 'g'
     writec %99
     %99 = 'e'
     writec %99
     %99 = ':'
     writec %99
     %99 = ' '
     writec %99
     %99 = 'a'
     writec %99
     %99 = '['
     writec %99
     %99 = 'i'
     writec %99
     %99 = ']'
     writec %99
     writeln
     halt
  label endIf2 :
     %14 = a[i]
     writei %14
  label endif3 :
     writes "\n"
     %15 = 1
     %16 = i - %15
     i = %16
     goto while1
  label endwhile1 :
     writes "bad message!"
     writes "\n"
     return
endfunction


