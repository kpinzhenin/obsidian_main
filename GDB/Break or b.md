Устанавливает точку останова.
Точка останова может задаваться:
номером строки
```c
(gdb) b 5
Breakpoint 1 at 0x1155: file tst.c, line 6.
```
указателем на "символ" (например имя функции). При этом исполнение прервется при первом обнаружении символа (функции)
```c
(gdb) b foo
```