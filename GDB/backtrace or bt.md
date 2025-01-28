Показывает точку входа в функцию. Больше я ничего полезного не увидел.
```c
int main(void)
{
	int a = x + 10;
	int b = 3;
	b = a; 
	a = foo(b);	
	b++;
	int local_c = b +10;
	b = foo(local_c);
	++a;
	(void)a;
	printf("end of prog \n");
	return 0;
}

(gdb) bt
#0  main () at tst.c:13
// next use step to next instruction, will go to "a = foo(b)"
16		a = foo(b);	
(gdb) s
foo (in=20) at tst.c:6
6		int first_arg = 2, second_arg = 3;
(gdb) bt
#0  foo (in=20) at tst.c:6
#1  0x00005555555551a0 in main () at tst.c:16
// now show input point of "main" and "foo"
```