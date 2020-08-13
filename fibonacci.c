#include<stdio.h>

int fib(int n) 
{
    int result = 0, t0 = 0, t1 = 1, i;
    for(i = 2; i <= n; i++)
    {
        result = t0 + t1;
        t0 = t1;
        t1 = result;
    }
    return result;
}

int fibonacciRecursive(int n)
{
    if(n <= 1)
        return n;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}
int f[10];
int fibonacciImproved(int n)
{
    if(n <= 1)
    {
        f[n] = n;
        return n;
    }
    else
    {
        if(f[n-1] == -1)
        {
            f[n-1] = fibonacciImproved(n-1);
        }
        if(f[n-2] == -1)
        {
            f[n-2] = fibonacciImproved(n-2);
        }
        f[n] = f[n-1] + f[n-2];
        return f[n-1] + f[n-2];
    } 
}

void main()
{
    printf("%d\t", fib(9));
    printf("%d\t", fibonacciRecursive(9));
    printf("%d\t", fibonacciImproved(9));
}