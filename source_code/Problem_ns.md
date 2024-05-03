```c
void problem_ns(int num, int base, int *res)
{
while(num > 0)
    {      
        printf("%d", *(res--) = (num % base));
        num /= base;        
    }
    printf(" \n");
}
```
