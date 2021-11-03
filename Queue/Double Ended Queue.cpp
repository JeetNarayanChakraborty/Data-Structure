#include<iostream>
using namespace std;

class DEQueue
{
    private:
    
        int front;
        int* DEQ;
        int rear;
        int size;
        
    public:
        
        void create()
        {
            cout<<"Enter size of Double ended queue :";
            cin>>size;
            
            DEQ=new int[size];
            
            front=-1;
            rear=-1;
        }
            
        bool isFull()
        {
            if(front==size-1)
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
                front++;
                cout<<"Enter number :";
                cin>>DEQ[front];
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
                DEQ[rear+1]=0;
                rear++;
            }
        }
        
        void display()
        {
            int i;
            
            for(i=rear+1;i<=front;i++)
            {
                cout<<DEQ[i]<<" ";
            }
        }
};


int main()
{
    int j,n;
    
    DEQueue q;
    
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









