/* Bubble sort Algorithm */


#include <iostream>
using namespace std;


void swap(int&,int&);
void bubble_sort(int [],int);



int main()
{
    int a[10]={0},i;
    
    for(i=0;i<10;i++)
    {
        cout<<"Enter number :";
        cin>>a[i];
    }
    
    cout<<endl<<"Before sorting :";
    
    for(i=0;i<10;i++)
    {
        cout<<a[i]<<" ";
    }
    
    bubble_sort(a,10);
    
    cout<<endl<<"After sorting :";
    
    for(i=0;i<10;i++)
    {
        cout<<a[i]<<" ";
    }
    
    
    
    
    return 0;
}


void swap(int& k,int& l)
{
    int temp;
    
    temp=k;
    k=l;
    l=temp;
}


void bubble_sort(int a[],int s)
{
    int m,n;
    
    for(m=0;m<s;m++)
    {
        for(n=0;n<s;n++)
        {
            if(a[n]>a[n+1])
            {
                swap(a[n],a[n+1]);
            }
        }
    }
}



