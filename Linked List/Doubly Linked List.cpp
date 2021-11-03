#include<iostream>
#include<cmath>
using namespace std;

class DLinked
{
    private:
        
        DLinked *prev;
        int data;
        DLinked *next;
    
    public:
        
        DLinked* create(DLinked *head,int a[],int n)
        {
            DLinked *temp,*p;
            int i;
            
            temp=new DLinked;
            temp->prev=NULL;
            temp->data=a[0];
            temp->next=NULL;
            head=temp;
            p=temp;
            
            for(i=1;i<n;i++)
            {
                temp=new DLinked;
                
                temp->prev=p;
                temp->data=a[i];
                temp->next=NULL;
                
                p->next=temp;
                p=temp;
            }
            
            return head;
        }
        
        void display(DLinked *head)
        {
            DLinked *s;
            s=head;
            
            while(s!=NULL)
            {
                cout<<s->data<<" ";
                s=s->next;
            }
        } 
        
        int length(DLinked *head)
        {
            DLinked *p;
            int i=0;
            
            p=head;
            
            while(p!=NULL)
            {
                p=p->next;
                i++;
            }
            
            return i;
        }
        
        DLinked* end(DLinked *head)
        {
            DLinked *p;
            
            p=head;
            
            while(p->next!=NULL)
            {
                p=p->next;
            }
            
            return p;
        }
        
        void search(DLinked *head)
        {
            DLinked *p;
            int n,i=1;
            
            p=head;
            
            cout<<"Enter number to search :";
            cin>>n;
            
            while(p!=NULL)
            {
                if(p->data==n)
                {
                    cout<<endl<<"Number found at "<<i;
                    break;
                }
                
                p=p->next;
                i++;
            }
        }
        
        void minmax(DLinked *head,int& min,int& max)
        {
            DLinked *p;
            
            p=head;
            
            while(p!=NULL)
            {
                if(min>p->data)
                {
                    min=p->data;
                }
                
                p=p->next;
            }
            
            p=head;
            
            while(p!=NULL)
            {
                if(max<p->data)
                {
                    max=p->data;
                }
                
                p=p->next;
            }
        }
        
        DLinked* insert(DLinked *head,int ind,DLinked*& tail)
        {
            DLinked *temp,*p;
            int i;
            
            temp=new DLinked;
            
            cout<<"Enter value :";
            cin>>temp->data;
            
            if(ind==1)
            {
                temp->next=head;
                temp->prev=NULL;
                head=temp;
                
                return head;
            }
            else if(ind==(length(head)+1))
            {
                tail->next=temp;
                temp->prev=tail;
                temp->next=NULL;
                tail=temp;
                
                return head;
            }
            else
            {
                p=head;
                
                for(i=0;i<ind-2;i++)
                {
                    p=p->next;
                }
                
                temp->next=p->next;
                p->next->prev=temp;
                p->next=temp;
                temp->prev=p;
                
                return head;
            }
        }
        
        DLinked* del(DLinked *head,int ind,DLinked*& tail)
        {
            DLinked *p,*temp;
            int i;
            
            if(ind==1)
            {
                temp=head;
                head=head->next;
                head->prev=NULL;
                delete temp;
                
                return head;
            }
            else if(ind==(length(head)))
            {
                temp=tail;
                temp->prev->next=NULL;
                tail=temp->prev;
                delete temp;
                
                return head;
            }
            else
            {
                temp=head;
                
                for(i=0;i<ind-1;i++)
                {
                    temp=temp->next;
                }
                
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
                delete temp;
                
                return head;
            }
        }
        
        
        DLinked* reverse(DLinked *head,DLinked *tail,DLinked *revhead)
        {
            DLinked *p;
            int l,k=0;
            
            l=length(head);
            
            int ar[l];
            
            p=tail;
            
            while(p!=NULL)
            {
                ar[k]=p->data;
                k++;
                p=p->prev;
            }
            
            revhead=create(revhead,ar,l);
            
            return revhead;
        }
        
        DLinked* reverse2(DLinked *revhead)
        {
            DLinked *p,*q,*r;
            
            p=revhead;
            q=revhead;
            r=NULL;
            
            while(q->next!=NULL)
            {
                q=q->next;
            }
            
            
            while(p!=NULL)
            {
                if(p==revhead)
                {
                    p->prev=p->next;
                    p->next=NULL;
                }
                else if(p==q)
                {
                    p->next=p->prev;
                    p->prev=NULL;
                }
                else
                {
                    r=p->prev;
                    p->prev=p->next;
                    p->next=r;
                }
                
                
               p=p->prev; 
            }
            
            revhead=q;
            
            return revhead;
        }
        
        void mid(DLinked *head)
        {
            DLinked *p;
            int j;
            
            p=head;
        
            
            if(length(head)%2==0)
            {
                for(j=0;j<(length(head)/2)-1;j++)
                {
                    p=p->next;
                }
                
                cout<<"Middle element is "<<p->data;
            }
            else
            {
                for(j=0;j<floor(length(head)/2);j++)
                {
                    p=p->next;
                }
                
                cout<<"Middle element is "<<p->data;
            }
        }
};



int main()
{
    DLinked d;
    
    DLinked *head,*tail,*revhead;
    int ind,j,k,min=10000,max=0;
    
    int a[]={100,200,300,400,500,600,700,800};
    
    head=d.create(head,a,8);
    tail=d.end(head);
    
    cout<<"Doubly Linked list created"<<endl<<endl;
    d.display(head);
    cout<<endl<<"Length :"<<d.length(head)<<endl;
    cout<<"How many number to enter :";
    cin>>j;
    
    for(k=0;k<j;k++)
    {
        cout<<"Where do you want to insert , first, last:"<<d.length(head)+1<<" or any other position ? ";
        cin>>ind;
    
        head=d.insert(head,ind,tail);
    }
    
    cout<<endl;
    d.display(head);
    cout<<endl;
    
    cout<<endl<<"How many number to delete :";
    cin>>j;
    
    for(k=0;k<j;k++)
    {
        cout<<"Where do you want to delete , first, last:"<<d.length(head)<<" or any other position ? ";
        cin>>ind;
    
        head=d.del(head,ind,tail);
    }
    
    cout<<endl;
    d.display(head);
    cout<<endl<<endl;
    d.search(head);
    cout<<endl<<endl;
    d.minmax(head,min,max);
    cout<<"Maximum :"<<max<<", Minimum :"<<min;
    cout<<endl<<endl<<"Reversing Doubly Linked List :"<<endl<<endl;
    revhead=d.reverse(head,tail,revhead);
    d.display(revhead);
    cout<<endl;
    cout<<endl<<"Again reversing Doubly Linked List :"<<endl<<endl;
    revhead=d.reverse2(revhead);
    d.display(revhead);
    cout<<endl<<endl;
    d.mid(head);
    
    
    return 0;
}













