```c
void Problem_FS(int DecimalBaseNum)
{
	int n = 2;
	while(DecimalBaseNum > 0)
	{
		printf("[%d] ", DecimalBaseNum % n);
		DecimalBaseNum = DecimalBaseNum / n;
		n++;
	}
	printf("\n");
}
```