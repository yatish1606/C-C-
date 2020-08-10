#include<stdio.h>

double taylorSeriesRecursive(double x, double n)
{
    static double power = 1, factorial = 1;
    if(n == 0)
        return 1;
    power *= x;
    factorial *= n;
    return taylorSeriesRecursive(x, n-1) + power/factorial;
}

double taylorSeriesRecursiveEfficient(int x, int n)
{

}

void main()
{
    printf("Result is %lf", taylorSeriesRecursive(5.0, 4.0));
}

/*
OUTPUT FOR taylorSeriesRecursive(5.0, 4.0) => e^5 upto 4 terms

e^0 => 1
e^x upto n terms = e^(n-1) + x^n/n!

So e^5 upto 4 terms = e^5 upto 3 terms + x^4/4!
e^5 upto 3 terms = e^5 upto 2 terms + x^3/3!

power/factorial addition is done at return time so use static int and increment in each call
static int value will start increasing for each call while in the descending part of recursion for
each call. 



*/ 