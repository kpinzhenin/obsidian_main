Выводит исходный код программы без аргументов
```c
(gdb) l
1	#include <stdio.h>
2	
3	int main(void)
4	{
5		int x;
6		int a = x;
7		int b = x;	
8		int c = a + b;
9		printf("c = %d \n", c);
10		return 0;
}
```
по умолчанию вывод по 10 строк исходного коды. Количество выводимых строк можно изменить командой 
```c
(gdb) set listsize 13
(gdb) show listsize 
Number of source lines gdb will list by default is 13.
```