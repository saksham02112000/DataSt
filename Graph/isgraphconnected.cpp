#include <bits/stdc++.h>
using namespace std;
vector<bool> visited;
vector<vector<int>> adj;


vector<int> getthecomponents(int source,vector<int> &arr)
{
    
    visited[source]=true;
    arr.push_back(source);
    for(auto i: adj[source])
    {   
        if(!visited[i])
        {
            getthecomponents(i,arr);
        }
    }
    return arr;
}


void solve()
{
    int m,n;
    cin>>n>>m;
    adj=vector<vector<int>> (n);
    visited=vector<bool> (n, false);
    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i =0; i < n; i++)
    {
        if(!visited[i]){
            vector<int> arr;
            adj.push_back(getthecomponents(i,arr));
        }
    }
    for(auto i: adj)
    {
        for(auto j:i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return;
}
int main()
{
    long long int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

// 1
// 7
// 5
// 0 1
// 2 3
// 4 5
// 5 6
// 4 6
