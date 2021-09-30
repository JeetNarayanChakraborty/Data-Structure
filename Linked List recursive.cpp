#include<iostream>
using namespace std;

class linked
{
    private:
        int data;
        linked *next;
    public:
        linked* create(int a[],int n,linked *head)
        {
            int i;
            linked *temp,*p;
            head=new linked;
            head->data=a[0];
            p=head;

            for(i=1;i<n;i++)
	        {
	            temp=new linked;
	            temp->data=a[i];
	            temp->next=NULL;
	            p->next=temp;
	            p=p->next;            
	        }
	        
	        return head;
        }
        
        void display(linked *head,linked *t)
        {
            if(t!=NULL)
            {
                cout<<t->data<<" ";
                display(head,t->next);
            }
        }
        
        bool search(linked *head,linked *t,int v,bool b)
        {
            if(t!=NULL)
            {
                b=search(head,t->next,v,b);
                
                if(v==t->data)
                {
                    b=true;
                }
                
                return b;
                
            }
            
            else
            {
                return false;
            }

        }
        
        int count(linked *head,linked *t)
        {
            int i=0,sum=0;
            
            if(t!=NULL)
            {
                return(count(head,t->next)+(t->data));
            }
            else
            {
                return 0;
            }
        }
        
        int max(linked *head,linked *t)
        {
            int m=0;
            
            if(t!=NULL)
            {
               m=max(head,t->next);
               
               if(m<t->data)
               {
                    m=t->data;
                    cout<<m<<" ";
                    return m;
               }
            }
            else
            {
                return 0;
            }
        }
};


int main()
{
    linked l;
    linked *head,*t;
    bool b=false;
    
    int a[]={10,20,30,40,50,60,70,80};

    head=l.create(a,8,head);
    t=head;
    
    l.display(head,t);
    cout<<endl;
    if(l.search(head,t,70,b))
    {
        cout<<"Number found";
    }
    else
    {
        cout<<"Number not found";
    }
    cout<<endl;
    cout<<l.count(head,t);
    cout<<endl;
    cout<<"Maximum number is "<<l.max(head,t);
}


