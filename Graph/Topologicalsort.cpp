#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> adj(n);
    vector<int> ind(n, 0);
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        ind[v]++;
    }
    queue<int> q;
    for (int i = 0; i < n; ++i)
    {
        if (ind[i] == 0)
            q.push(i);
        //        cout<<"hi";
    }

    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        cout << x << " ";
        for (auto itr : adj[x])
        {
            ind[itr]--;
            if (ind[itr] == 0)
            {
                q.push(itr);
            }
            //                cout<<"hey";
        }
    }

    return 0;
}