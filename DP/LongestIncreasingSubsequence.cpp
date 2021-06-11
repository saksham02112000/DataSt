#include <bits/stdc++.h>
using namespace std;

int lis(int *arr, int size)
{
    int *output = new int[size + 1];
    output[0] = 1;
    for (int i = 1; i < size + 1; ++i)
    {
        output[i] = 1;
        for (int j = i - 1; j >= 0; --j)
        {
            if (arr[j] > arr[i])
            {
                continue;
            }
            int possibleans = output[j] + 1;
            if (possibleans > output[i])
            {
                output[i] = possibleans;
            }
        }
    }
    int best = 0;
    for (int i = 0; i < size + 1; ++i)
    {
        if (best < output[i])
            best = output[i];
    }
    return best;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    int ans = lis(arr, n);
    cout << ans;
    return 0;
}

// // test cases
// 8
// 10 22 9 33 21 50 41 60
// //ans
// 5