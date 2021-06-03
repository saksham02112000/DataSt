
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> vec;
vector<bool> vis;
vector<int> col;
bool bipartite = true;

void color(int i, int colour)
{
    if (col[i] != -1 && col[i] != colour)
    {
        bipartite = false;
        return;
    }
    col[i] = colour;
    if (vis[i])
        return;
    vis[i] = true;
    for (auto itr : vec[i])
    {
        color(itr, colour xor 1);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vec = vector<vector<int>>(n);
    vis = vector<bool>(n, false);
    col = vector<int>(n, -1);
    for (int i = 0; i < n; ++i)
    {
        int u, v;
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    for (int i = 0; i < n; ++i)
    {
        if (!vis[i])
        {
            color(i, 0);
        }
    }
    cout << bipartite;
    return 0;
}