#include<iostream>
using namespace std;

class Pqueue;

class Elements
{
    private:
    
        char c;
        int pr;
    
    public:
    
        void take()
        {
            cout<<endl<<"Enter process name :";
            cin>>c;
            cout<<"Enter Priority :";
            cin>>pr;
        }
        
    friend void display(Pqueue[],int);
    friend void work(Elements[],int,Pqueue[],int);
};


class Pqueue
{
    private:
    
        int front;
        char* Pq;
        int rear;
        int size;
        
    public:
    
        void create()
        {
            size=4;
            Pq=new char[size];
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
        
        void insert(char ch)
        {
            if(isFull())
            {
                cout<<endl<<"Queue is Full"<<endl;
            }
            else
            {
                rear++;
                Pq[rear]=ch;
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
                Pq[front+1]='\0';
                front++;
            }
        }
        
        friend void display(Pqueue[],int);
        friend void work(Elements[],int,Pqueue[],int);
};



int main()
{
    int n,i;
    Pqueue p[10];
    
    for(i=0;i<10;i++)
    {
        p[i].create();
    }
    
    cout<<"How many processes are there ? ";
    cin>>n;
    
    Elements e[n];
    
    for(i=0;i<n;i++)
    {
        e[i].take();
    }
    
    work(e,n,p,10);
    
    cout<<endl<<endl;
    
    display(p,10);
    
    
    
    return 0;
}


void work(Elements e[],int n,Pqueue p[],int l)
{
    int i,j;
    char ch;
    
    for(i=0;i<n;i++)
    {
        ch=e[i].c;
        j=e[i].pr;
        p[j-1].insert(ch);
    }
}

void display(Pqueue p[],int l)
{
    int i,j;
    
    for(i=0;i<l;i++)
    {
        cout<<"Priority Queue "<<i+1<<" ";
        
        for(j=0;j<4;j++)
        {
            if(p[i].Pq[j]!='\0')
            {
                cout<<p[i].Pq[j]<<" ";
            }
        }
        
        cout<<endl;
    }
}



