#include<stdio.h>

int nCr(int n, int r)
{
    if(r == 0 || n == r)
    {
        return 1;
    }
    return nCr(n-1,r) + nCr(n-1,r-1); 
}

void main()
{
    printf("%d\n", nCr(5,2));
}

/*
Uses concept of Pascals Triangle : P
                            1 
                            /\
                          1    1
                          /\    / \
                        1    "2"     1
                        /\   / \   /\
                      1    3    "3"   1       

for nCr, n = number of rows from 0, r = rth element in the rows starting from 0
so , 3C2 =  3rd row starting from 0, second element starting from 0
so , 2C1 = 2nd row, first element 

r <= n always 

So, 2C1 calls 1C0 and 1C1, which call 0C0,
so nCr calls (n-1)C(r-1) and (n-1)C(r)

TIME COMPLEXITY : O(2^n) as function calls itself twice 

*/ 