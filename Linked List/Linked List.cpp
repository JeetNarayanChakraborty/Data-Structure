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
                cout<<p->data<<" ";
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
        
        linked* end(linked *head)
        {
            linked *p;
            
            p=head;
            
            while(p->next!=NULL)
            {
                p=p->next;
            }
            
            return p;
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
                temp->next=head;
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
        
        linked* join(linked*& tail,linked *head,linked *head2) 
        {
            tail->next=head2;
            
            return head;
        }
        
        
        linked* Merge(linked *head,linked *head2)
        {
            linked *last,*third,*start;
            
            if(head->data<head2->data)
            {
                third=last=head;
                head=head->next;
                third->next=NULL;
                start=head;
            }
            else
            {
                third=last=head2;
                head2=head2->next;
                third->next=NULL;
                start=head2;
            }
            while(head && head2)
            {
                if(head->data < head2->data)
                {
                    last->next=head;
                    last=head;
                    head=head->next;
                    last->next=NULL;
 
                }
                else
                {
                    last->next=head2;
                    last=head2;
                    head2=head2->next;
                    last->next=NULL;
                }
            }
            
            if(head)
            {
                last->next=head;
            }
            
            else if(head2)
            {
                last->next=head2;
            }
            
            return start;
        }
};



int main()
{
    linked l;
    linked *head,*head2,*tail,*tail2;
    int i,j,ind;
    bool b=true;
    int de;
    
    int a[]={10,20,30,40,50,60,60,80};
    int c[]={15,21,54,78,92,118,130,145};

    head=l.create(a,8,head);
    head2=l.create(c,8,head2);
    
    tail=l.end(head);
    tail2=l.end(head2);
    
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
    
    cout<<endl;
    l.display(head);
    cout<<endl;
    
    cout<<endl<<"Number of elements to delete :";
    cin>>j;
    
    for(i=0;i<j;i++)
    {
        cout<<"Where to delete First,last "<<l.count(head)<<",or any other position ?";
        cin>>ind;
        
        head=l.del(head,ind,tail);
    }
    
    cout<<endl;
    l.display(head);
    cout<<endl;
    
    l.duplicate(head,tail,b);
    cout<<endl<<"After removing duplicates"<<endl;
    l.display(head);
    cout<<endl;
    
    
    cout<<endl<<"Do you want to join or merge two Linked lists ? ";
    cin>>de;
    
    
    if(de==1)
    {
        cout<<endl<<"After Joining";
        head=l.join(tail,head,head2);
        cout<<endl;
        l.display(head);
    }
    else
    {
        cout<<endl<<"After Merging"<<endl;
        head=l.Merge(head,head2); 
        l.display(head);
    }
    
    return 0;
}








