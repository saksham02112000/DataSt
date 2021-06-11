#include <bits/stdc++.h>
using namespace std;

int num_codesdp(int number[], int size)
{
    int *output = new int[size + 1];
    output[0] = 1;
    output[1] = 1;
    for (int i = 2; i < size + 1; ++i)
    {
        output[i] = output[i - 1];
        if (number[i - 2] * 10 + number[i - 1] <= 26)
        {
            output[i] += output[i - 2];
        }
    }
    int ans = output[size];
    delete[] output;
    return ans;
}

int num_codes(int *n, int size, vector<int> &arr)
{
    if (size == 1)
        return 1;
    if (size == 0)
        return 1;
    if (arr[size] > 0)
        return arr[size];
    int output = num_codes(n, size - 1, arr);
    if (arr[size - 2] * 10 + arr[size - 1] <= 26)
    {
        output += num_codes(n, size - 2, arr);
    }
    arr[size] = output;
    return output;
}

int main()
{
    int size;
    cin >> size;
    int number[size];
    for (int i = 0; i < size; ++i)
    {
        cin >> number[i];
    }
    vector<int> arr(size, 0);
    int ans = num_codesdp(number, size);
    cout << ans;
    return 0;
}
