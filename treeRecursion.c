#include<stdio.h>

void fun(int n) {
    if(n > 0) {
        printf("%d\t", n);
        fun(n-1);
        fun(n-1);
    }
}

void main() {
    int a = 3;
    fun(a);
}

/*
OUTPUT : 3  2   1   1   2   1   1

Tree Recursion => Function calls itself multiple times

First 3 is printed, then fun(2) is called. fun(2) calls fun(1) twice, each time fun(1) is called, 
1 is printed and fun(0) is called by fun(1) twice. fun(0) terminates.
Here, 3211 is printed. 
Again fun(2) is called second time and 211 is printed again

TIME COMPLEXITY : Equal to the number of times function is called. Here , function is called 15 times. 
So, for n = 3, function is called 2^(3+1) -1 times, ie 2^(n+1) -1 times. 
So, TC => O(2^n)

SPACE COMPLEXITY : At any given time, space used will be equal to number of activation records in stack. 
The number of activation records will be maximum when execution is the farthest point from root of tree, ie
at maximum height of the tree. For n, maximum height is (n+1). At a time, max 4 records will be there. 
So SC => O(n)

                        fun(3)
                        /   \
                p3  fun(2)    fun(2)
                    /   |       |   \
            p2  fun(1) fun(1) fun(1) fun(1) p2
                /   \   / \     / \     / \ 
        p1  fun(0) fun(0) fun(0) fun(0) fun(0) fun(0) fun(0) fun(0)
        fun(0) => no output 

*/