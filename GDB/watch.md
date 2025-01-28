```c
11	int main(void)
12	{
13		int a = x + 10;
14		int b = 3;
15		a = foo();
16		b++;
17		b = foo();
18		++a;
19		printf("end of prog \n");
20		return 0;
21  }
```
чтобы gdb увидел локальные переменные необходимо после запуска исполняемого файла в отладчике. запустить программу на исполнение командой [[start]]
Добавить переменную как отслеживаемую.
```c
Temporary breakpoint 1, main () at tst.c:13
13
(gdb) watch a
Hardware watchpoint 2: a
```
Исполнение будет прерываться всякий раз, как значение переменной будет меняться. Для продолжения выполения набрать команду [[continue or c]]
```c
(gdb) c
Continuing.

Hardware watchpoint 2: a

Old value = -8408
New value = 20
main () at tst.c:14
14		int b = 3;
(gdb) c
Continuing.

Hardware watchpoint 2: a

Old value = 20
New value = 5
main () at tst.c:16
16		b++;
```