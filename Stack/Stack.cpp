#include<iostream>
using namespace std;

class Stack1
{
    private:
    
        int size;
        int top;
        int *a;
        
    public:
    
        void create()
        {
            cout<<"Enter Stack Size :";
            cin>>size;
            a=new int[size];
            top=-1;
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
        
        void push()
        {
            int v;

            if(top==size-1)
            {
                cout<<endl<<"Stack overflow"<<endl;
            }
            else
            {
                cout<<"Enter Number :";
                cin>>v;
                top++;
                a[top]=v;
            }
        }
        
        void pop()
        {
            if(top==-1)
            {
                cout<<"Stack underflow";
            }
            else
            {
                cout<<"Deleted :"<<a[top]<<endl;
                a[top]=0;
                top--;
            }
        }
        
        void peek(int pos)
        {
            if(pos>=0&&pos<=size)
            {
                cout<<"Position "<<pos<<":"<<a[size-pos];
            }
        }
        
        bool isEmpty()
        {
            if(top==-1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        
        bool isFull()
        {
            if(top==size-1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
            
        void stacktop()
        {
            if(top==-1)
            {
                cout<<"There is no element";
            }
            else
            {
                cout<<"Stack top :"<<a[top];
            }
        }
};

class Stack2
{
    private:
        
        int size=50;
        int top;
        char *str;
    
    public:
        
        void create()
        {
            str=new char[size];
            top=-1;
        }
        
        void push(char c)
        {
            if(top==size-1)
            {
                cout<<endl<<"Stack overflow"<<endl;
            }
            else
            {
                top++;
                str[top]=c;
            }
        }
        
        void pop()
        {
            if(top==-1)
            {
                cout<<"Stack underflow";
            }
            else
            {
                str[top]='\0';
                top--;
            }
        }
        
        bool isEmpty()
        {
            if(top==-1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        
        char bracket(char ch)
        {
            if(ch==')')
            {
                return '(';
            }
            else if(ch=='}')
            {
                return '{';
            }
            else
            {
                return '[';
            }
        }
        
        void Parmatch(char arr[],int ar)
        {
            int i=0;
            
            while(arr[i]!='\0')
            {
                if(arr[i]=='('||arr[i]=='{'||arr[i]=='[')
                {
                    push(arr[i]);
                    i++;
                }
                else if(arr[i]==')'||arr[i]=='}'||arr[i]==']')
                {
                    char temp;
                    
                    temp=bracket(arr[i]);
                    
                    if(str[top]==temp)
                    {
                        pop();
                        i++;
                    }
                    else
                    {
                        cout<<"wrong Parenthesis given at character :"<<arr[i];
                        break;
                    }
                }
                else
                {
                    i++;
                }
            }
            
            if(isEmpty())
            {
                cout<<endl<<"Paranthesis is balanced";
            }
            else
            {
                cout<<endl<<"Paranthesis is not balanced";
            }
        }
        
        int oprec(char cr)
        {
            if(cr=='+'||cr=='-')
            {
                return 1;
            }
            else if(ch=='*'||cr=='/')
            {
                return 2;
            }
            else if(ch=='(')
            {
                return 7;
            }
            else
            {
                return 0;
            }
        }
        
        int iprec(char cr)
        {
            if(cr=='+'||cr=='-')
            {
                return 2;
            }
            else if(ch=='*'||cr=='/')
            {
                return 4;
            }
            else
            {
                return 0;
            }
        }
        
        
        
        void reset()
        {
            str[50]={'\0'};
            top=-1;
        }
        
        bool isoperand(char cr)
        {
            if(cr!='+'&&cr!='-'&&cr!='*'&&cr!='/')
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        
        void toPostfix(char ar2[],int s2)
        {
            int i,j=0;
            
            char postf[s2];
            
            for(i=0;ar2[i]!='\0';i++)
            {
                if(ar2[i]=='+'||ar2[i]=='-'||ar2[i]=='*'||ar2[i]=='/')
                {
                    if(top==-1)
                    {
                        push(ar2[i]);
                    }
                    else if(oprec(ar2[i])>oprec(str[top]))
                    {
                        push(ar2[i]);
                    }
                    else
                    {
                        while(!isEmpty()&&(oprec(ar2[i])<=oprec(str[top])))
                        {
                            postf[j]=str[top];
                            j++;
                            pop();
                        }
                        
                        push(ar2[i]);
                    }
                }
                else
                {
                    postf[j]=ar2[i];
                    j++;
                }
            }
            
            while(!isEmpty())
            {
                postf[j]=str[top];
                j++;
                pop();
            }
            
            cout<<"Postfix expression is :";
            
            for(i=0;postf[i]!='\0';i++)
            {
                cout<<postf[i];
            }
        }
};



int main()
{
    Stack1 s;
    Stack2 st;
    int i,j,n,pos;
    char arr[100]={'\0'};
    char ar2[100]={'\0'};
    
    s.create();
    st.create();
    cout<<endl;
    
    if(s.isEmpty())
    {
        cout<<"Stack is empty"<<endl<<endl;
    }
    
    cout<<"How many numbers to enter ? ";
    cin>>n;
    
    for(j=0;j<n;j++)
    {
        s.push();
    }
    
    cout<<endl<<endl;
    s.display();
    
    if(s.isFull())
    {
        cout<<endl<<endl<<"Stack is full";
    }
    
    cout<<endl<<endl<<"How many numbers to delete ? ";
    cin>>n;
    
    for(j=0;j<n;j++)
    {
        s.pop();
    }
    
    cout<<endl;;
    s.display();
    cout<<endl<<endl;
    cout<<"Enter position to peek :";
    cin>>pos;
    cout<<endl;
    s.peek(pos);
    cout<<endl<<endl;
    s.stacktop();
    cout<<endl<<endl;
    
    cout<<"How many Characters to enter ? ";
    cin>>n;
    
    cout<<"Enter Expression :";
    
    for(j=0;j<n;j++)
    {
        cin>>arr[j];
    }
    
    st.Parmatch(arr,100);
    
    st.reset();
    
    cout<<endl<<endl<<"How many Characters to enter ? ";
    cin>>n;
    
    cout<<endl<<endl<<"Enter Infix Expression :";
    
    for(i=0;i<n;i++)
    {
        cin>>ar2[i];
    }
    
    st.toPostfix(ar2,100);
    
    
    return 0;
}
        
    
    
    






