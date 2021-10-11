/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/

#include<stdio.h>
#include<conio.h>

int fact(int);

int main()
{
    printf("%d",fact(10));

    return 0;
}

int fact(int n)
{
    if(n>0)
    {
        return(fact(n-1)*n);
    }
    else
    {
        return 1;
    }
}
