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
};



int main()
{
    linked l;
    linked *head,*tail;
    int i,j,ind;
    
    int a[]={10,20,30,40,50,60,70,80};

    head=l.create(a,8,head);
    tail=l.end(head,tail);
    
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
        cout<<"Where to enter First,last "<<l.count(head)<<",or any other position ?";
        cin>>ind;
        
        head=l.del(head,ind,tail);
    }
    
    l.display(head);
    
    return 0;
}







