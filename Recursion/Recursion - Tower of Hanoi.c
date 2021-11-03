/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/

#include<stdio.h>
#include<conio.h>

void TOH(int,int,int,int);

int main()
{
    TOH(16,1,2,3);
    
    return 0;
}

void TOH(int n,int a,int b,int c)
{
    static int k=0;
   
    if(n>0)
    {
        TOH(n-1,a,c,b);
        k++;
        printf("From %d to %d :%d\n",a,c,k-64485);
        TOH(n-1,b,a,c);
    }
}
