#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &vec, int n, int i)
{
    int maxInd = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && vec[l] > vec[maxInd])
        maxInd = l;
    if (r < n && vec[r] > vec[maxInd])
        maxInd = r;
    if (maxInd != i)
    {
        swap(vec[i], vec[maxInd]);
        heapify(vec, n, maxInd);
    }
}

void heapsort(vector<int> &vec)
{
    int n = vec.size();
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(vec, n, i);
    }

    for (int i = n - 1; i > 0; i--)
    {
        swap(vec[0], vec[i]);
        heapify(vec, i, 0);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> vec;

    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        vec.push_back(m);
    }
    heapsort(vec);

    for (int i = 0; i < n; i++)
    {
        cout << vec[i] << " ";
    }

    return 0;
}