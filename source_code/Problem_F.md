```c
unsigned long long Fibonachi_num(int n)
{
    if (n == 0) return n;
    
    int n_2 = 0, n_1 = 1 ,res = 0;      
    for(int i = 0; i < n; i++)
    {
        res = n_2 + n_1;
        if(i > 0 ) n_2 = n_1;
        n_1 = res;
    }
    return res;
}
```