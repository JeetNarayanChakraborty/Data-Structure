#include<iostream>
using namespace std;

class CirLinked
{
    private:
        int data;
        CirLinked *next;
        
    public:
        
        CirLinked* insert(CirLinked *head)
        {
            CirLinked *temp,*p;
            
            temp=new CirLinked;
            
            cout<<"Enter value :";
            cin>>temp->data;
            
            if(head==NULL)
            {
                head=temp;
                temp->next=head;
                
                return head;
            }
            else 
            {
                p=head;
                
               while(p->next!=head)
               {
                   p=p->next;
               }
               
               p->next=temp;
               temp->next=head;
               
               return head;
            }
        }
        
        void display(CirLinked *head)
        {
            CirLinked *p;
            
            p=head;
            
            do
            {
                cout<<p->data<<" ";
                p=p->next;
                
            }while(p!=head);
        }
        
        void RecuDisplay(CirLinked *head,CirLinked *r)
        {
            if(r->next!=head)
            {
                cout<<r->data<<" ";
                RecuDisplay(head,r->next);
            }
            else
            {
                cout<<r->data;
            }
        }
        
        
        CirLinked* del(CirLinked *head,int& i)
        {
            CirLinked *p,*q;
            int j;
            
            p=head;
            
            for(j=0;j<i-2;j++)
            {
                p=p->next;
            }
            
            i--;
            
            q=p->next;
            delete q;
            p->next=head;
            
            return head;
        }
};


int main()
{
    CirLinked l;
    int i=5,k=0;
    
    CirLinked *head=NULL,*r;
    
    head=l.insert(head);
    head=l.insert(head);
    head=l.insert(head);
    head=l.insert(head);
    head=l.insert(head);
    
    cout<<endl<<"After Inserting nodes"<<endl;
    l.display(head);
    cout<<endl;
    
    head=l.del(head,i);
    head=l.del(head,i);
    head=l.del(head,i);
    
    cout<<"After deleting nodes"<<endl;
    l.display(head); 
    r=head;
    cout<<endl<<"Recursive display"<<endl;
    l.RecuDisplay(head,r);

    return 0;
}
        
        
    





