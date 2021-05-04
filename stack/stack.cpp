#include<bits/stdc++.h>
using namespace std;
#define n 10
class sta
{
    int top;
    int *arr;
    public:
    sta()
    {
        arr=new int[n];
        top=-1;
    }

    void push(int x)
    {
        if(top==n-1)
        {
            cout<<"stackoverflow"<<endl;
            return;
        }
        top++;
        arr[top]=x;
        
    }

    void pop()
    {
        if(top==-1)
        {
            cout<<"No element to pop"<<endl;
            return;
        }
        
        top--;
    }
    int Top()
    {
        if(top==-1)
        {
            cout<<"No element in stack"<<endl;
            return -1;
        }
        return arr[top];
    }
    bool isEmpty()
    {
        return top==-1;
    }
};
int main()
{
    sta s;
    s.push(2);
    s.push(3);
    s.push(4);
    cout<<s.Top()<<endl;
    s.pop();
    cout<<s.Top()<<endl;
    return 0;
}