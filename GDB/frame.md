Печатает инфоромацию о текущем кадре стека.
```c
int num_less_then(int num)
{
	if(num == 0 )
		return 0;
	else 
		return num_less_then(num - 1);
}

int main(void)
{
	int n = 3;
	num_less_then(n);
	return 1;
}
```

после [[start]] имеем
```c
(gdb) frame
#0  main () at requrcion.c:12
12		int n = 3;
// показывает текущую функцию и следующую команду
```

посмотреть подробную информацию о кадре можно командой info f
```c
(gdb) info f
Stack level 0, frame at 0x7fffffffdd90:
 rip = 0x555555555138 in num_less_then (requrcion.c:4); saved rip = 0x555555555171
 called by frame at 0x7fffffffddb0
 source language c.
 Arglist at 0x7fffffffdd80, args: num=3
 Locals at 0x7fffffffdd80, Previous frame's sp is 0x7fffffffdd90
 Saved registers:
  rbp at 0x7fffffffdd80, rip at 0x7fffffffdd88

```

может вызываться со следующими парамтерами
```c
info f <addr> // addr - address of wanted frame
info args // list of argument of selected frame
info local // list of local var
info catch // list of exeption hundler
```