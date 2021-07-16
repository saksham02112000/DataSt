#include <bits/stdc++.h>
using namespace std;
vector<bool> visited;
vector<vector<int>> adj;
// vector<int> parent;


bool isCyclic(int source, int parent)
{
    visited[source]=true;
    // parent[source]=parentind;
    // cout<<source<<" "<<parent[source]<<endl;
    for(auto i: adj[source])
    {
        if(!visited[i])
        {
            bool foundcycle=isCyclic(i,source);
            if(foundcycle)
                return true; 
        }
        else
        {
            if(i==parent)
            {
                return false;
            }
        }
    }
    return false;
}

void solve()
{
    int m,n;
    cin>>n>>m;
    adj=vector<vector<int>> (n);
    visited=vector<bool> (n, false);
    // parent=vector<int> (n);
    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool ans=false;
    for(int i=0;i<n;i++)
    {
        ans=isCyclic(0,-1);
    }
    if(ans)
        cout<<"cyclic";
    else
        cout<<"not cyclic";


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