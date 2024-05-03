```c
int gcd(int x, int y) // expect x > y
{
    int q = x % y;
    for (;q > 0; q = x % y)
    {
        x = y; y = q;
    }
    return y;
    //q = x % y while q > 0
}
```