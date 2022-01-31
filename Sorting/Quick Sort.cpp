/* Quick sort Algorithm */



#include<iostream>
using namespace std;


void swap(int *,int *);
int partition(int [],int,int);
void Quick_sort(int [],int,int);


int main()
{
    int a[11]={0},i;
    
    a[10]=65535;
    
    
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
    
    Quick_sort(a,0,10);
    
    cout<<endl<<"After sorting :";
    
    for(i=0;i<10;i++)
    {
        cout<<a[i]<<" ";
    }
    
    
    
    
    return 0;
}



void swap(int *k,int *l)
{
    int temp;
    
    temp=*k;
    *k=*l;
    *l=temp;
}


int partition(int a[],int low,int high)
{
    int pivot,i,j;
    
    pivot=a[low];
    i=low;
    j=high;
    
    
    do
    {
        do
        {
            i++;
            
        }while(a[i]<=pivot);
        
        do
        {
            j--;
            
        }while(a[j]>pivot);
        
        if(i<j)
        {
            swap(a[i],a[j]);
        }
        
    }while(i<j);  
    
    
    swap(&a[low],&a[j]);
    
      
    
    return j;
}


void Quick_sort(int a[],int low,int high)
{
    int j;
    
    if(low<high)
    {
        j=partition(a,low,high);
        
        Quick_sort(a,low,j);
        Quick_sort(a,j+1,high);
    }
}
















