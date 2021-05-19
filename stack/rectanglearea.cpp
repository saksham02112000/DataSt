#include <bits/stdc++.h>
using namespace std;
int largestrectangle(vector<int> v)
{
    int n = v.size(), ans = 0, i = 0;
    stack<int> st;
    v.push_back(0);
    while (i < n)
    {
        while (!st.empty() and v[st.top()] > v[i])
        {
            int t = st.top();
            int h = v[t];
            st.pop();
            if (st.empty())
            {
                ans = max(ans, h * i);
            }
            else
            {
                int len = i - st.top() - 1;
                ans = max(ans, len * h);
            }
        }
        st.push(i);
        i++;
    }
    return ans;
}

int main()
{
    vector<int> vec;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        vec.push_back(m);
    }
    cout << largestrectangle(vec);

    return 0;
}