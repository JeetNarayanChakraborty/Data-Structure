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
        
        linked* end(linked *head,linked *tail)
        {
            tail=head;
            
            while(tail!=NULL)
            {
                tail=tail->next;
            }
            
            return tail;
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
        
        void reverse(linked *head,linked *tail,linked *t)
        {
            linked *previousNode=NULL,*currentNode=NULL,*nextNode=NULL,*temp;
            
            currentNode=head;
            
            while(currentNode!=NULL)
            {
                nextNode=currentNode->next;
                currentNode->next=previousNode;
                previousNode=currentNode;
                currentNode=nextNode;
            }
            
            temp=previousNode;
            cout<<endl<<endl;
            
            while(temp != NULL)
            {
                cout<<temp->data<<" ";
                temp = temp->next;
            }
        }
        
        
        bool is_loop(linked *head)
        {
            linked *p,*q;
            
            p=head;
            q=head;
            
            do
            {
                if((p!=NULL)&&(q!=NULL))
                {
                    p=p->next;
                    q=q->next;
                    
                    if(q!=NULL)
                    {
                        q=q->next;
                    }
                }
                else
                {
                    break;
                }
                
            }while(p!=q);
            
            if(p==q&&q!=NULL)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
};


int main()
{
    linked l;
    linked *head,*tail,*t;
    bool b=false;
    
    int a[]={10,20,30,40,50,60,70,80};

    head=l.create(a,8,head);
    tail=l.end(head,tail);
    
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
    l.reverse(head,tail,t);
    
    l.display(head,t);
    
    if(l.is_loop(head))
    {
        cout<<endl<<"Linked list contain Loop";
    }
    else
    {
        cout<<endl<<"Linked list doesn't contain Loop";
    }
}








