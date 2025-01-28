оказывается sizeof "незаконченного типа" приводит к ошибке...
```c
struct tst_type
{
	char char_array[]
}

sizeof(tst_type) // приведет в SIGSEGV - segmentation fault
```