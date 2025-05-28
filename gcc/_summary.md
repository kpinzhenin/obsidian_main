- специфичные версии gcc. Обозначаются *machine*-gcc-*version* (arm-gcc-noneabi )
посмотреть пути поиска "#include"
```bash
echo | gcc -xc -E -v -
```

компиляция файла ассемблер с помощью `gcc` производится опцией `-S`, полученный файл будет иметь расширение `.s`

скомпилтровать *переносимый исходный файл* `.o` или `.obj` в `windows` можно с помощью опции `-o`. Но делает это утилита `as`! Для той же операции в `gcc` используется опция `-c` иными словами :


как видно можно посмотерть таблицу символов объектного файла двумя способами, через утилиту `nm` или `objdump -t (--syms)` или `readelf -s`
```c
teddy@teddy-MS-7A34:~/gcc_objdump$ nm tst_gcc.o
000000000000003c T add
0000000000000000 D global_var1
0000000000000000 B global_var_not_init
0000000000000000 T main

teddy@teddy-MS-7A34:~/gcc_objdump$ objdump -t tst_gcc.o

tst_gcc.o:     file format elf64-x86-64

SYMBOL TABLE:
0000000000000000 l    df *ABS*	0000000000000000 tst_gcc.c
0000000000000000 l    d  .text	0000000000000000 .text
0000000000000000 g     O .data	0000000000000004 global_var1
0000000000000000 g     O .bss	0000000000000004 global_var_not_init
0000000000000000 g     F .text	000000000000003c main
000000000000003c g     F .text	0000000000000018 add

teddy@teddy-MS-7A34:~/gcc_objdump$ readelf -s tst_gcc.o

Symbol table '.symtab' contains 7 entries:
   Num:    Value          Size Type    Bind   Vis      Ndx Name
     0: 0000000000000000     0 NOTYPE  LOCAL  DEFAULT  UND 
     1: 0000000000000000     0 FILE    LOCAL  DEFAULT  ABS tst_gcc.c
     2: 0000000000000000     0 SECTION LOCAL  DEFAULT    1 .text
     3: 0000000000000000     4 OBJECT  GLOBAL DEFAULT    3 global_var1
     4: 0000000000000000     4 OBJECT  GLOBAL DEFAULT    4 global_var_not_init
     5: 0000000000000000    60 FUNC    GLOBAL DEFAULT    1 main
     6: 000000000000003c    24 FUNC    GLOBAL DEFAULT    1 add

```

посмотреть символы 