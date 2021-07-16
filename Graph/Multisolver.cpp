#include <bits/stdc++.h>
using namespace std;
vector<bool> visited;
vector<vector<pair<int,int>>> adj;

void findlongest(int source, int destination, string ssf,int pathsum, int &longestpath, string &stringlongest)
{
    cout<<source<<" "<<destination<<" "<<pathsum<<endl;
    // int longestpath=INT_MIN; string stringlongest;
    if(source==destination)
    {
        if(longestpath<=pathsum)
        {
            longestpath=pathsum;
            stringlongest=ssf;
        }
        return;
    }
    visited[source]=true;
    for(auto i: adj[source])
    {
        if(!visited[i.first])
        findlongest(i.first, destination, ssf+(char)(i.first+48), pathsum+i.second, longestpath, stringlongest);
    }
    visited[source]=false;
}


void solve()
{
    int m,n;
    cin>>n>>m;
    adj=vector<vector<pair<int,int>>> (n);
    visited=vector<bool> (n, false);
    for (int i = 0; i < m; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].emplace_back(v,w);
        adj[v].emplace_back(u,w);
    }
    int source, destination;
    cin>>source>>destination;
    int longestpath=INT_MIN; string stringlongest="";
    findlongest(source, destination,"",0, longestpath, stringlongest);
    cout<<longestpath<<" "<<stringlongest;
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
// 9
// 0 1 10
// 1 2 10
// 2 3 10
// 0 3 40
// 3 4 2
// 4 5 3
// 5 6 3
// 4 6 8
// 2 5 5
// 0
// 6