/* Insertion sort Algorithm */


#include <iostream>
using namespace std;


void Insertion_sort(int *);


int main()
{
    int i,a[10],*arr;
    
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
    
    cout<<endl<<"After sorting :";
    
    Insertion_sort(a);
    
    
    
    
    
    return 0;
}



void Insertion_sort(int *p)
{
    int ci,cv,i,j,l=0;
    
    for(i=1;i<10;i++)
    {
        cv=p[i];
        ci=i;
        j=i-1;
        
        while(j>=0 && p[j]>cv)
        {
            p[j+1]=p[j];
            j--;
            l++;
        }
        
        p[ci-l]=cv;
        l=0;
    }
    
    for(i=0;i<10;i++)
    {
        cout<<p[i]<<" ";
    }
}

















