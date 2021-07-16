#include <bits/stdc++.h>
using namespace std;
vector<bool> visited;
vector<vector<int>> adj;




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