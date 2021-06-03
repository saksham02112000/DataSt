#include <bits/stdc++.h>
using namespace std;
vector<int> parent;
vector<int> weight;
vector<vector<pair<int, int>>> adj;
vector<bool> visited;

void prims(int source)
{
    if (visited[source])
        return;
    visited[source] = true;
    weight[source] = 0;
    parent[source] = -1;
    queue<int> q;
    q.push(source);
    while (!q.empty())
    {
        int main = q.front();
        q.pop();
        for (auto it : adj[main])
        {
            if (!visited[it.first])
            {
                q.push(it.first);
                visited[it.first] = true;
            }
            if (weight[it.first] > it.second)
            {
                weight[it.first] = it.second;
                parent[it.first] = main;
            }
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    adj = vector<vector<pair<int, int>>>(n);
    visited = vector<bool>(n, false);
    weight = vector<int>(n, INT_MAX);
    parent = vector<int>(n, -1);
    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u - 1].push_back({v - 1, w});
        adj[v - 1].push_back({u - 1, w});
    }
    int source;
    cin >> source;
    prims(source);
    int cost = 0;
    for (int i = 0; i < n; ++i)
    {
        cost += weight[i];
    }
    cout << cost;
    return 0;
}