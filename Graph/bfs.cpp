
//bfs
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> vec[n];
    vector<bool> vis(n, false);
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        vec[x].push_back(y);
        vec[x].push_back(x);
    }
    queue<int> q;
    q.push(1);
    vis[1] = true;
    while (!q.empty())
    {
        int st = q.front();
        q.pop();
        cout << st << " ";
        vis[st] = true;
        for (int &itr : vec[st])
        {
            if (!vis[itr])
            {
                vis[itr] = true;
                q.push(itr);
            }
        }
    }

    return 0;
}

// not working