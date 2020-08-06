#include<stdio.h>

int glo = 0;
int function(int n)
{
    static int x = 0;
    if(n > 0)
    {
        x++;
        glo++;
        printf("\nx modified as %d", x);
        return x + function(n-1);
        // Same as funciton(n-1) + x even though x should ideally not change at that moment
    }
    return 0;
}

void main()
{
    int a = 5;
    int r = function(a);
    printf("%d\n",r);
}