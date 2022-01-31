/* Selection sort Algorithm */



#include <iostream>
using namespace std;


void swap(int&,int&);
void Selection_sort(int [],int);


int main()
{
    int a[10],i;
    
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
    
    
    Selection_sort(a,10);
    
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


void Selection_sort(int a[],int s)
{
    int me=10000,i,j,k,l,ce;
    
    for(i=0;i<s;i++)
    {
        ce=a[i];
        k=i;
        
        for(j=i;j<10;j++)
        {
            if(me>a[j])
            {
                me=a[j];
                l=j;
            }
        }
        
        if(ce>me)
        {
            swap(a[k],a[l]);
        }
        
        me=10000;
    }
}












