#include<stdio.h>

int power(int m, int n)
{
    if(n == 0)
        return 1;
    return power(m, n-1)*m;
}

int powerEfficient(int m, int n) 
{
    if(n == 0)
        return 1;
    if(n % 2 == 0)
    {
        return power(m*m, n/2);
    }
    else return m*power(m*m, (n-1)/2);
}

void main() 
{
    printf("Power is %d\t", power(2,9));
    printf("Power is %d\t", powerEfficient(2,9));
}