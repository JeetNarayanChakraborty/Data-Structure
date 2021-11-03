#include<iostream>
using namespace std;

class cirQueue
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
        
        void insert()
        {
            if(rear+1==front)
            {
                cout<<endl<<"Queue is Full"<<endl;
            }
            else if(rear==size-1)
            {
                rear=-1;
                rear++;
                cout<<"Enter number :";
                cin>>a[rear];
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
            if(front==rear)
            {
                cout<<endl<<"Queue is Empty"<<endl;
            }
            else if(front==size-1)
            {
                front=-1;
                a[front+1]=0;
                front++;
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
            
            for(i=0;i<size;i++)
            {
                if(a[i]!=0)
                {
                    cout<<a[i]<<" ";
                }
            }
        }
};


int main()
{
    char c='y';
    int j;
    
    cirQueue q;
    
    q.create();
    
    while(c=='y')
    {
        cout<<"Want to insert or delete number ?";
        cin>>j;
        
        if(j==1)
        {
            q.insert(); 
        }
        else
        {
            q.del();
        }
        
        
        cout<<"Continue ? ";
        cin>>c;
    }
    
    cout<<endl;
    q.display();
    
    
    
    
    return 0;
}








