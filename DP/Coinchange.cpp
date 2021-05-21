//recursive solution coin change problem
//dp solution of coi change problem
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 2;
int dp[N][N];
int noofchances(int arr[], int target, int coins)
{
    if (target == 0)
        return 1;
    if (target < 0)
        return 0;
    if (coins <= 0)
        return 0;
    if (dp[target][coins] != -1)
    {
        return dp[target][coins];
    }

    dp[target][coins] = noofchances(arr, target - arr[coins - 1], coins) + noofchances(arr, target, coins - 1);
    return dp[target][coins];
}

int main()
{
    int target, coins;
    cin >> target >> coins;
    int arr[coins];
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            dp[i][j] = -1;
        }
    }
    for (int i = 0; i < coins; ++i)
    {
        cin >> arr[i];
    }
    cout << noofchances(arr, target, coins) << endl;
    return 0;
}
