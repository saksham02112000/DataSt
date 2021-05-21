#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    priority_queue<int, vector<int>> pq;
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        pq.push(i);
    }
    for (int i = 0; i < k - 1; i++)
    {
        pq.pop();
    }
    cout << pq.top();

    return 0;
}