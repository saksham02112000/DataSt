#include <iostream>
using namespace std;

void reverse(int arr[], int startind, int endindex)
{
    while (startind < endindex)
        swap(arr[startind++], arr[endindex--]);
}
int binarysearch(int arr[], int start, int end, int key)
{
    int index = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] <= key)
            end = mid - 1;
        else
        {
            start = mid + 1;
            if (index == -1 || arr[index] >= arr[mid])
                index = mid;
        }
    }
    return index;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    int pt = n - 1;
    while (pt >= 0)
    {
        if (arr[pt - 1] < arr[pt])
        {
            pt--;
            break;
        }
        pt--;
    }
    if (pt < 0)
        reverse(arr, 0, n - 1);
    else
    {
        int ind = binarysearch(arr, pt + 1, n - 1, arr[pt]);
        //        cout<<ind<<endl;
        swap(arr[ind], arr[pt]);
        reverse(arr, pt + 1, n - 1);
    }
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
}