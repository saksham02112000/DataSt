#include<bits/stdc++.h>
using namespace std;
void stock(int arr[],int ans[],int n)
{
    stack<int> st;
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && arr[st.top()]<=arr[i])
        {
            st.pop();
        }
        if(st.empty())
        {
            ans[i]=i+1;
        }
        else
        {
            ans[i]=i-st.top();
        }
        st.push(i);
    }
}
int main()
{
    int price[7] = { 100, 80, 60, 70, 60, 75, 85 };
    int span[7] = { 0 };
    stock(price,span,7);
    for (int i = 0; i < 7; i++)
    {
        cout<<span[i]<<endl;
        /* code */
    }

    return 0;
}