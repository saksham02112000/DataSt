#include <bits/stdc++.h>
using namespace std;
#define f(i, j, k, in) for (int i = j; i < k; i += in)
#define rf(i, j, k, in) for (int i = j; i >= k; i -= in)
#define fr(i, j) f(i, 0, j, 1)
#define pb push_back
#define all(a) a.begin(), a.end()
#define rall(a) a.end(), a.begin()
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef unordered_map<int, int> umpii;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;
void mergeRow(vvi &arr, int startindexi, int startindexy, int midindexx, int midindexy, int endindexx, int endindexy)
{
    for (int row = startindexi; row <= endindexx; row++)
    {
        int n1 = midindexy - startindexy + 1;
        int n2 = endindexy - midindexy;
        int L[n1], R[n2];
        for (int i = 0; i < n1; i++)
        {
            L[i] = arr[row][startindexy + i];
        }
        for (int j = 0; j < n2; j++)
        {
            R[j] = arr[row][midindexy + 1 + j];
        }
        int i = 0;
        int j = 0;
        int k = startindexy;
        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
            {
                arr[row][k] = L[i];
                i++;
            }
            else
            {
                arr[row][k] = R[j];
                j++;
            }
            k++;
        }
        while (i < n1)
        {
            arr[row][k] = L[i];
            i++;
            k++;
        }
        while (j < n2)
        {
            arr[row][k] = R[j];
            j++;
            k++;
        }
    }
    for (int cln = startindexy; cln <= endindexy; cln++)
    {
        int n1 = midindexx - startindexi + 1;
        int n2 = endindexx - midindexx;
        int L[n1], R[n2];
        for (int i = 0; i < n1; i++)
        {
            L[i] = arr[startindexi + i][cln];
        }
        for (int j = 0; j < n2; j++)
        {
            R[j] = arr[midindexx + 1 + j][cln];
        }
        int i = 0;
        int j = 0;
        int k = startindexi;
        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
            {
                arr[k][cln] = L[i];
                i++;
            }
            else
            {
                arr[k][cln] = R[j];
                j++;
            }
            k++;
        }
        while (i < n1)
        {
            arr[k][cln] = L[i];
            i++;
            k++;
        }
        while (j < n2)
        {
            arr[k][cln] = R[j];
            j++;
            k++;
        }
    }
}
void mergeSort(vvi &arr, int startindexi, int startindexy, int endindexx, int endindexy)
{
    if (startindexi >= endindexx && startindexy >= endindexy)
    {
        return;
    }
    int midindexx = ((endindexx - startindexi + 1) % 2 == 1) ? (startindexi + (endindexx - startindexi + 1) / 2) : (startindexi + (endindexx - startindexi) / 2);
    int midindexy = ((endindexy - startindexy + 1) % 2 == 1) ? (startindexy + (endindexy - startindexy + 1) / 2) : (startindexy + (endindexy - startindexy) / 2);
    mergeSort(arr, startindexi, startindexy, midindexx, midindexy);
    mergeSort(arr, startindexi, startindexy + midindexy + 1, midindexx, endindexy);
    mergeSort(arr, startindexi + midindexx + 1, startindexy, endindexx, midindexy);
    mergeSort(arr, startindexi + midindexx + 1, startindexy + midindexy + 1, endindexx, endindexy);
    mergeRow(arr, startindexi, startindexy, midindexx, midindexy, endindexx, endindexy);
}
int main()
{
    int m, n;
    cin >> m >> n;
    vvi arr(m, vi(n));
    fr(i, m)
    {
        fr(j, n)
        {
            cin >> arr[i][j];
        }
    }
    mergeSort(arr, 0, 0, m - 1, n - 1);
    fr(i, m)
    {
        fr(j, n)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}