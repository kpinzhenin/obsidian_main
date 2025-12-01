В общем случае - описывает состояние выпляемой программы.
Информация о текущем состоянии от текущих точках остановки
```c
(gdb) info b
um     Type           Disp Enb Address            What
1       breakpoint     keep n   0x0000000000001155 in main at tst.c:6
```

информация о начальном-конечном адресе функции (допустим main)
```c
1	#include <stdio.h>
2	int x = 10;
3	
4	int foo(int in)
5	{
6		int first_arg = 2, second_arg = 3;
7		return in + first_arg + second_arg; 
8	}
9	
10	
(gdb) 
11	int main(void)
12	{
13		int a = x + 10;
```
```c

```

```c
info files
```
	показывает информацию о размерах и адресах секций вызывнного файла.
	```c
	Local exec file:
		`/home/teddy/otus-c-2024-07/otus-c-2024-07-pinzhenin/HW-5-asm/hw', file type elf64-x86-64.
		Entry point: 0x401000
		0x0000000000401000 - 0x0000000000401023 is .text
		0x0000000000402000 - 0x000000000040200e is .rodata
		0x0000000000403010 - 0x0000000000403040 is .data
		0x00007ffff7ffd120 - 0x00007ffff7ffd168 is .hash in system-supplied DSO at 0x7ffff7ffd000
		0x00007ffff7ffd168 - 0x00007ffff7ffd1c4 is .gnu.hash in system-supplied DSO at 0x7ffff7ffd000
		0x00007ffff7ffd1c8 - 0x00007ffff7ffd300 is .dynsym in system-supplied DSO at 0x7ffff7ffd000
		0x00007ffff7ffd300 - 0x00007ffff7ffd38b is .dynstr in system-supplied DSO at 0x7ffff7ffd000
		0x00007ffff7ffd38c - 0x00007ffff7ffd3a6 is .gnu.version in system-supplied DSO at 0x7ffff7ffd000
		0x00007ffff7ffd3a8 - 0x00007ffff7ffd3e0 is .gnu.version_d in system-supplied DSO at 0x7ffff7ffd000
		0x00007ffff7ffd3e0 - 0x00007ffff7ffd500 is .dynamic in system-supplied DSO at 0x7ffff7ffd000
		0x00007ffff7ffd500 - 0x00007ffff7ffd554 is .note in system-supplied DSO at 0x7ffff7ffd000
		0x00007ffff7ffd554 - 0x00007ffff7ffd5b0 is .eh_frame_hdr in system-supplied DSO at 0x7ffff7ffd000
		0x00007ffff7ffd5b0 - 0x00007ffff7ffd6f0 is .eh_frame in system-supplied DSO at 0x7ffff7ffd000
		0x00007ffff7ffd6f0 - 0x00007ffff7ffdf9d is .text in system-supplied DSO at 0x7ffff7ffd000
		0x00007ffff7ffdf9d - 0x00007ffff7ffe06f is .altinstructions in system-supplied DSO at 0x7ffff7ffd000
		0x00007ffff7ffe06f - 0x00007ffff7ffe0ab is .altinstr_replacement in system-supplied DSO at 0x7ffff7ffd000
	
	```

```c
info registers
```
	отображает информацию о текущем состоянии регистров
	```c
	(gdb) info registers 
	rax            0x0                 0
	rbx            0x0                 0
	rcx            0x0                 0
	rdx            0x0                 0
	rsi            0x0                 0
	rdi            0x0                 0
	rbp            0x0                 0x0
	rsp            0x7fffffffde18      0x7fffffffde18
	r8             0x0                 0
	r9             0x0                 0
	r10            0x0                 0
	r11            0x0                 0
	r12            0x0                 0
	r13            0x0                 0
	r14            0x0                 0
	r15            0x0                 0
	rip            0x401001            0x401001 <_start+1>
	eflags         0x202               [ IF ]
	cs             0x33                51
	ss             0x2b                43
	ds             0x0                 0
	es             0x0                 0
	fs             0x0                 0
	gs             0x0                 0
	fs_base        0x0                 0
	gs_base        0x0                 0
	
	```