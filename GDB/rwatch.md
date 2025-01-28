```c
{
13		int a = x + 10;
14		int b = 3;
15		a = foo(b);
16		b++;
17		int local_c = b +10;
18		b = foo(local_c);
19		++a;
20		printf("end of prog \n");
21		return 0;
}
```
также как [[watch]] необходимо запустить программу на исполнение, чтобы отслеживать переменные в стеке (иначе их там еще не будет)
```c
(gdb) start
Temporary breakpoint 1, main () at tst.c:13
13		int a = x + 10;
(gdb) rwatch b
Hardware read watchpoint 2: b
(gdb) c
Continuing.
//переменная считалась, для того что бы инициализироваться :14
Hardware read watchpoint 2: b

Value = 3
0x0000555555555193 in main () at tst.c:15
15		a = foo(b);
(gdb) c
Continuing.
//переменная считалась, для того чтобы инкрементироваться :16
Hardware read watchpoint 2: b

Value = 4
0x00005555555551a4 in main () at tst.c:17
17		int local_c = b +10;

```
в общем то до к онца не понятно, когда переменная "читается", а  когда нет....