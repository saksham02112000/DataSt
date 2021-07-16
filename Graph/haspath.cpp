#include <bits/stdc++.h>
using namespace std;
vector<bool> visited;
vector<vector<int>> adj;
bool hasneighbour(int source, int destination)
{
    if(source==destination)
    {
        return true;
    }
    visited[source]=true;
    for(auto i: adj[source])
    {
        if(!visited[i])
        {
           bool hasdes=hasneighbour(i,destination);
           if(hasdes)
            return true;
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
    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int source,end;
    cin>>source>>end;
    cout<<hasneighbour(source, end);
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
// 8
// 0 1
// 1 2
// 2 3
// 0 3
// 3 4
// 4 5
// 5 6
// 4 6
// 0
// 6