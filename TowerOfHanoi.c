#include<stdio.h>

void TOH(int numberOfDisks, int A, int B, int C)
{
    if(numberOfDisks == 0)
    {
        return;
    }
    TOH(numberOfDisks-1, A, C, B);
    printf("%d --> %d\n", A, C);
    TOH(numberOfDisks-1, B, A, C);
}

void main()
{
    TOH(3,1,2,3);
}


/*
Tower of Hanoi describes the minimum number of steps to shift n disks from tower A to tower C
First we transfer one disk from A to B
Then we transfer it from B to C
Each call will call itself with lesser number of disks and follow the same strategy

TIME COMPLEXITY : O(2^n) because TOH calls itself twice



*/ 