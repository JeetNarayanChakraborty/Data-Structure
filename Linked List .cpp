#include<iostream>
using namespace std;

class linked
{
    private:
        int data;
        linked *next;
    public:
        linked* create(int arr[],int n,linked *head)
        {
            int i;
            linked *temp,*p;
            head=new linked;
            head->data=arr[0];
            p=head;

            for(i=1;i<n;i++)
	        {
	            temp=new linked;
	            temp->data=arr[i];
	            temp->next=NULL;
	            p->next=temp;
	            p=p->next;
	        }
	        
	        return head;
        }
        
        void display(linked *head)
        {
            linked *p;
            p=head;
            
            while(p!=NULL)
            {
                cout<<p->data<<endl;
                p=p->next;
            }
        }
        
        void search(linked *head,int v)
        {
            linked *p;
            int i=1;
            bool b=false;
            
            for(p=head;p->next!=NULL;p=p->next)
            {
                if(v==p->data)
                {
                    b=true;
                    break;
                }
    
                i++;
            }

            if(b)
            {
                cout<<"Number found at :"<<i;
            }   
            else
            {
                cout<<"Number not found";
            }
        }
        
        int count(linked *head)
        {
            linked *p;
            p=head;
            int i=0;
            
            while(p!=NULL)
            {
                i++;
                p=p->next;
            }
            
            return i;
        }
        
        void minmax(linked *head)
        {
            linked *p;
            int max=0,min=1000;
            p=head;
            
            while(p!=NULL)
            {
                if(max<p->data)
                {
                    max=p->data;
                }
                
                p=p->next;
            }
            
            p=head;
            
            while(p!=NULL)
            {
                if(min>p->data)
                {
                    min=p->data;
                }
                
                p=p->next;
            }
            
            cout<<"Min is "<<min<<" , ";
            cout<<"Max is "<<max;
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
        
        linked* insert(linked *head,int ind,linked *tail)
        {
            linked *temp,*p;
            int v,i;
            
            p=head;
            
            cout<<"Enter value :";
            cin>>v;
            
            if(ind==1)
            {
                temp=new linked;
                temp->data=v;
                temp->next=head->next;
                head=temp;
                
                return head;
            }
            else if(ind==(count(head)+1))
            {
                    temp=new linked;
                    temp->data=v;
                    temp->next=NULL;
                    tail->next=temp;
                    
                    return head;
            }
            else
            {
                temp=new linked;
                temp->data=v;
                
                for(i=0;i<ind-2;i++)
                {
                    p=p->next;
                }
                
                temp->next=p->next;
                p->next=temp;
                
                return head;
            }
        }
        
        linked* del(linked *head,int ind,linked *tail)
        {
            linked *p,*q;
            int i;
            
            p=head;
            
            if(ind==1)
            {
                q=head->next;
                delete p;
                head=q;
                
                return head;
            }
            else if(ind==(count(head)+1))
            {
                for(i=0;i<count(head)-2;i++)
                {
                    p=p->next;
                }
                
                delete tail;
                tail=p;
                
                return head;
            }
            else
            {
                for(i=0;i<ind-2;i++)
                {
                    p=p->next;
                }
                
                q=p->next;
                p->next=q->next;
                delete q;
                
                return head;
            }
        }
        
        bool is_sorted(linked *head,bool b)
        {
            linked *p,*q;
            
            p=head->next;
            q=head;
            
            while(p!=NULL)
            {
                if(p->data<q->data)
                {
                    b=false;
                }
                
                p=p->next;
                q=q->next;
            }
            
            return b;
        }
        
        void duplicate(linked *head,linked *tail,bool b)
        {
            linked *p,*q;
            int i=1;
            
            p=head->next;
            q=head;
            
            if(is_sorted(head,b))
            {
            
                while(p!=NULL)
                {
                    if(q->data==p->data)
                    {
                        del(head,i,tail);
                    }
                
                    i++;
                    p=p->next;
                    q=q->next;
                }
            }
            else
            {
                cout<<"Make the list sorted first";
            }
        }
        
    /*    linked* join(linked *tail,linked *head,linked *head2) 
        {
            tail->next=head2;
            
            return head;
        }
    */
        
        linked* merge(linked *head,linked *head2) 
        {
            linked *p,*q,*r,*t,*s;
            
            p=head;
            q=p->next;
            t=head2;
            s=p;
            
            while(q!=NULL)
            {
                while(t!=NULL)
                {
                    r=t;
            
                    if(r->data>p->data&&r->data<q->data)
                    {
                        s->next=r;
                        r->next=q;
                        s=r;
                    }
                    
                    t=t->next;
                }
                
                p=p->next;
                q=q->next;
                t=head2;
            }
            
            return head;
        }
};



int main()
{
    linked l;
    linked *head,*head2,*tail,*tail2;
    int i,j,ind;
    bool b=true;
    
    int a[]={10,20,30,40,50,60,60,80};
    int c[]={54,92,118,6,78,15,21,145};

    head=l.create(a,8,head);
    head2=l.create(c,8,head2);
    
    tail=l.end(head,tail);
    tail2=l.end(head2,tail2);
    
    l.display(head);
    cout<<endl;
    l.search(head,70);
    cout<<endl;
    l.count(head);
    cout<<endl;
    l.minmax(head);
    
    cout<<endl<<"Number of elements to enter :";
    cin>>j;
    
    for(i=0;i<j;i++)
    {
        cout<<"Where to enter First,last "<<l.count(head)<<",or any other position ?";
        cin>>ind;
        
        head=l.insert(head,ind,tail);
    }
    
    l.display(head);
    
    cout<<endl<<"Number of elements to delete :";
    cin>>j;
    
    for(i=0;i<j;i++)
    {
        cout<<"Where to delete First,last "<<l.count(head)<<",or any other position ?";
        cin>>ind;
        
        head=l.del(head,ind,tail);
    }
    
    l.display(head);
    
    l.duplicate(head,tail,b);
    cout<<endl<<"After removing duplicates"<<endl;
    l.display(head);
    
    
/*  cout<<"Joining two Linked lists";
    head=l.join(tail,head,head2); 
    
    l.display(head); */
    cout<<"After Merging"<<endl;
    
    head=l.merge(head,head2); 
    
    l.display(head);
    
    return 0;
}












