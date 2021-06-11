class Solution
{
public:
    vector<vector<int>> vec;
    int partition(vector<vector<int>> &vec, int N, int arr[], int sum, int index)
    {
        if (sum == 0)
        {
            return 1;
        }
        if (index < 0 || index >= N)
        {
            return 0;
        }
        if (vec[index][sum] != -1)
        {
            return vec[index][sum];
        }
        return vec[index][sum] = partition(vec, N, arr, sum - arr[index], index + 1) || partition(vec, N, arr, sum, index + 1);
    }
    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for (int i = 0; i < N; i++)
        {
            sum += arr[i];
        }
        if (sum % 2 != 0)
        {
            return 0;
        }
        vec = vector<vector<int>>(N + 1, vector<int>(sum / 2 + 1, -1));
        return partition(vec, N, arr, sum / 2, 0);
        // code here
    }
};