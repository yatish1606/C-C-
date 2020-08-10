#include <stdio.h>

int sumFormula(int n)
{
    return (n*(n+1)) /2;
}

int sumIteration(int n)
{
    int sum = 0;
    int i = 1;
    for(i=1; i<=n; i++)
    {
        sum += i;
    }
    return sum;
}

int sumRecursion(int n)
{
    if(!n)
        return 0;
    return n + sumRecursion(n-1);
}

void main()
{
    int a = 5;
    printf("Using formula : ", sumFormula(a));
    printf("Using iterations : ", sumIteration(a));
    printf("Using recursion : ", sumRecursion(a));
}