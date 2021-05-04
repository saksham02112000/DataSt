#include<bits/stdc++.h>
using namespace std;
int answer(int v[],int n)
{
    stack<int> st;
    int ans=0;
   for(int i=0;i<n;i++)
   {
       while(!st.empty() and v[st.top()]<v[i])
       {
           int curr= st.top();
           st.pop();
           if(st.empty())
           {
               break;
           }
           int diff= i- st.top()-1;
           ans+=(min(v[st.top()],v[i])- v[curr])*diff;            
       }
       st.push(i);
   }
    return ans; 
}

int main()
{
    int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << answer(arr, n);
     
    return 0;


}