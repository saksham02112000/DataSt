#include <bits/stdc++.h>
using namespace std;
vector<bool> visited;
vector<vector<int>> adj;

vector<int> connectedcomp(int source, vector<int> &abc)
{
    // vector<int> abc;
    cout<<source<<endl;
    visited[source]=true;
    abc.push_back(source);
    for(auto i: adj[source])
    {
        if(!visited[i])
        {
            return connectedcomp(i,abc);
        }
    }
    return abc;
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
    vector<vector<int>> arr;
    for(int i=0;i<n;i++)
    {
        vector<int> abc;
        if(!visited[i]){
            cout<<"i: "<<i<<endl;
            arr.push_back(connectedcomp(i,abc));
        }
    }
    for(auto i=0;i<arr.size();i++)
    {
        for(auto j=0;j<arr[i].size();j++)
        {
            cout<<j<<" ";
        }cout<<endl;
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
// 7
// 0 1
// 1 2
// 2 3
// 0 3
// 4 5
// 5 6
// 4 6