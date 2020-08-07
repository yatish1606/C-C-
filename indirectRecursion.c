#include<stdio.h>
void funB(int);

void funA(int n) {
    if(n > 0)
    {
        printf("%d\t", n);
    }
    funB(n-1);
}

void funB(int n) {
    if(n > 1) 
    {
        printf("%d\t", n);
    }
    funA(n/2);
}

void main() {
    funA(20);
}

/*
OUTPUT : 20      19      9       8       4       3       1       

TIME COMPLEXITY : Depends on number of function calls

*/