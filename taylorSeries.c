#include<stdio.h>

int taylorSeriesRecursive(int x, int n)
{
    static int power = 1, factorial = 1;
    if(n == 0)
        return 1;
    power *= x;
    factorial *= n;
    return taylorSeriesRecursive(x, n-1) + power/factorial;
}

int taylorSeriesRecursiveEfficient(int x, int n)
{
    
}

void main()
{
    printf("Result is %d", taylorSeriesRecursive(5, 4));
}