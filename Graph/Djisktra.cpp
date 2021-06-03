#include <bits/stdc++.h>
using namespace std;
vector<int> parent;
vector<bool> visited;
vector<int> value;
vector<vector<pair<int, int>>> graph;

int selectMinVertex()
{
    int min = INT_MAX;
    int vertex;
    for (int i = 0; i < graph.size(); ++i)
    {
        if (!visited[i] && value[i] < min)
        {
            vertex = i;
            min = value[i];
        }
    }
    return vertex;
}

void djikstra(int source)
{
    parent[source] = -1;
    value[source] = 0;
    for (int i = 0; i < graph.size() - 1; ++i)
    {
        int U = selectMinVertex();
        visited[U] = true;
        for (auto it : graph[U])
        {
            if (!visited[it.second])
            {
                if (value[it.second] > value[U] + it.first)
                {
                    value[it.second] = value[U] + it.first;
                    parent[i] = U;
                }
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    graph = vector<vector<pair<int, int>>>(n);
    visited = vector<bool>(n, false);
    value = vector<int>(n, INT_MAX);
    parent = vector<int>(n);
    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({w, v});
        graph[v].push_back({w, u});
    }
    int source;
    cin >> source;
    djikstra(source);
    for (int i = 1; i < n; ++i)
    {
        cout << "U->V: " << parent[i] << "-> " << i << "->" << value[i] << "\n";
    }
    return 0;
}