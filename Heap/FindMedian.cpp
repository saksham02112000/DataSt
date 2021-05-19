#include <bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>> maxhp;
priority_queue<int, vector<int>, greater<int>> minhp;
void median(int ele)
{
    if (minhp.size() == maxhp.size())
    {
        if (maxhp.empty())
        {
            maxhp.push(ele);
        }
        else
        {
            if (ele < maxhp.top())
            {
                maxhp.push(ele);
            }
            else
            {
                minhp.push(ele);
            }
        }
    }
    else
    {
        if (maxhp.size() > minhp.size())
        {
            if (ele >= maxhp.top())
            {
                minhp.push(ele);
            }
            else
            {
                int temp = maxhp.top();
                maxhp.pop();
                maxhp.push(ele);
                minhp.push(temp);
            }
        }
        else
        {
            if (ele <= minhp.top())
            {
                maxhp.push(ele);
            }
            else
            {
                int temp = minhp.top();
                minhp.pop();
                minhp.push(ele);
                maxhp.push(temp);
            }
        }
    }
}
double findmedian()
{
    if (maxhp.size() == minhp.size())
    {
        return (maxhp.top() + minhp.top()) / 2.0;
    }
    else
    {
        if (maxhp.size() > minhp.size())
            return maxhp.top();
        else
            return minhp.top();
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> vec;
    for (int i = 0; i < n; ++i)
    {
        int m;
        cin >> m;
        median(m);
        cout << findmedian() << endl;
    }
    return 0;
}