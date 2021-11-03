#include<iostream>
using namespace std;

class Queue
{
    private:
    
        int front;
        int* a;
        int rear;
        int size;
    
    public:
        
        void create()
        {
            cout<<"Enter Size of Queue :";
            cin>>size;
            
            a=new int[size];
            
            front=-1;
            rear=-1;
        }
        
        bool isFull()
        {
            if(rear==size-1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        
        bool isEmpty()
        {
            if(front==rear)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        
        void insert()
        {
            if(isFull())
            {
                cout<<endl<<"Queue is Full"<<endl;
            }
            else
            {
                rear++;
                cout<<"Enter number :";
                cin>>a[rear];
            }
        }
        
        void del()
        {
            if(isEmpty())
            {
                cout<<endl<<"Queue is Empty"<<endl;
            }
            else
            {
                a[front+1]=0;
                front++;
            }
        }
        
        void display()
        {
            int i;
            
            for(i=front+1;i<=rear;i++)
            {
                cout<<a[i]<<" ";
            }
        }
};


int main()
{
    int j,n;
    
    Queue q;
    
    q.create();
    
    cout<<"How many numbers to enter ? ";
    cin>>n;
    
    for(j=0;j<n;j++)
    {
        q.insert();
    }
    
    cout<<endl;
    q.display();
    cout<<endl<<endl;
    
    cout<<"How many numbers to delete ? ";
    cin>>n;
    
    for(j=0;j<n;j++)
    {
        q.del();
    }
    
    cout<<endl;
    q.display();
    
    
    
    return 0;
}











