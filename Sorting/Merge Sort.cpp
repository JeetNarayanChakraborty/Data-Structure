/* Merge sort Algorithm */


#include<iostream>
using namespace std;


void merge (int *a, int low, int mid, int high)
{
    int i,j,k,nl,nr;

    nl=mid-low+1;
    nr=high-mid;

    int leftArr[nl],rightArr[nr];

    for(i=0;i<nl;i++)
    {
        leftArr[i]=a[low+i];
    }

    for(j=0;j<nr;j++)
    {
        rightArr[j]=a[mid+1+j];
    }


    i=0;
    j=0;
    k=low; 


    while(i<nl && j<nr)
    {
        if(leftArr[i]<=rightArr[j])
	    {
	        a[k] = leftArr[i];
	        i++;
	    }
        else
	    {
	        a[k] = rightArr[j];
	        j++;
	    }
	    
        k++;
    }


    while(i<nl)
    {
        a[k]=leftArr[i];
        i++;
        k++;
    }

    while (j < nr)
    {
        a[k] = rightArr[j];
        j++;
        k++;
    }
}


void Merge_sort (int *a, int low, int high)
{
    int mid;

    if (low<high)
    {
        mid=low+(high-low)/2;

        Merge_sort (a,low,mid);
        Merge_sort (a,mid+1,high);

        merge (a,low,mid,high);
    }
}


int main()
{
    int i,a[10];
    
    for(i=0;i<10;i++)
    {
        cout<<"Enter number :";
        cin>>a[i];
    }

    cout<<endl<<"Before sorting :";

    for (i=0;i<10;i++)
    {
        cout << a[i] << " ";
    }

    Merge_sort (a,0,9);

    cout<<endl<<"After sorting :";

    for(i=0;i<10;i++)
    {
        cout<<a[i]<<" ";
    }
    
    
    

    return 0;
}



