//kmp algo
#include <iostream>
using namespace std;
void kmp(int arr[], string &s, int n, string &f)
{
    arr[0] = 0;
    int i = 0, j = 1;
    while (j < n)
    {
        if (s[i] == s[j])
        {
            arr[j] = arr[j - 1] + 1;
            i++;
        }
        else
        {
            if (i != 0)
            {
                i = arr[i - 1];
                continue;
            }
            else
                arr[j] = 0;
        }
        j++;
    }
    return;
}
int main()
{
    int n;
    cin >> n;
    string s, f;
    cin >> s;
    int arr[n];
    cin >> f;
    kmp(arr, s, n, f);
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
//18
//adadabadadabadadad
//adad
//output of array
//0 0 1 2 3 0 1 2 3 4 5 6 7 8 9 10 11 12