
#include <bits/stdc++.h>
using namespace std;

void merge(int **arr, int startindx, int startindy, int endindexx, int endindexy, int midindexx, int midindexy);

void mergesort(int **arr, int stindx, int startindy, int m, int n)
{
    if (stindx >= m && startindy >= n)
    {
        return;
    }

    int midx = 0, midy = 0;
    if ((m - stindx + 1) % 2 == 0)
        midx = (m - stindx) / 2 + stindx;
    else
        midx = ((m - stindx + 1) / 2) + stindx;
    if ((n - startindy + 1) % 2 == 0)
        midy = (n - startindy) / 2 + startindy;
    else
        midy = ((n - startindy + 1) / 2) + startindy;

    mergesort(arr, stindx, startindy, midx, midy);
    mergesort(arr, stindx, startindy + midy + 1, midx, n);
    mergesort(arr, stindx + midx + 1, startindy, m, midy);
    mergesort(arr, stindx + midx + 1, startindy + midy + 1, m, n);
    merge(arr, stindx, startindy, m, n, midx, midy);
}

void merge(int **arr, int startindx, int startindy, int endindexx, int endindexy, int midindexx, int midindexy)
{

    for (int k = startindx; k <= endindexx; ++k)
    {
        int fa = midindexy - startindy + 1;
        int fb = endindexy - midindexy;
        int larr[fa], rarr[fb];
        for (int i = 0; i < fa; i++)
        {
            larr[i] = arr[k][startindy + i];
        }
        for (int j = 0; j < fb; j++)
        {
            rarr[j] = arr[k][midindexy + 1 + j];
        }

        int i = 0;
        int j = 0;
        int p = startindy;

        while (i < fa && j < fb)
        {
            if (larr[i] <= rarr[j])
            {
                arr[k][p] = larr[i];
                i++;
            }
            else
            {
                arr[k][p] = rarr[j];
                j++;
            }
            p++;
        }
        while (i < fa)
        {
            arr[k][p] = larr[i];
            i++;
            p++;
        }
        while (j < fb)
        {
            arr[k][p] = rarr[j];
            j++;
            p++;
        }
    }

    for (int k = startindy; k <= endindexy; ++k)
    {
        int la = midindexx - startindx + 1;
        int lb = endindexx - midindexx;
        int larrc[la], rarrc[lb];
        for (int i = 0; i < la; i++)
        {
            larrc[i] = arr[startindx + i][k];
        }
        for (int j = 0; j < lb; j++)
        {
            rarrc[j] = arr[midindexx + 1 + j][k];
        }

        int i = 0;
        int j = 0;
        int p = startindx;

        while (i < la && j < lb)
        {
            if (larrc[i] <= rarrc[j])
            {
                arr[p][k] = larrc[i];
                i++;
            }
            else
            {
                arr[p][k] = rarrc[j];
                j++;
            }
            p++;
        }
        while (i < la)
        {
            arr[p][k] = larrc[i];
            i++;
            p++;
        }
        while (j < lb)
        {
            arr[p][k] = rarrc[j];
            j++;
            p++;
        }
    }
}

int main()
{
    int m, n;
    cin >> m >> n;
    int **arr;
    arr = new int *[m];
    for (int i = 0; i < m; i++)
    {
        arr[i] = new int[n];
        for (int j = 0; j < n; ++j)
        {
            cin >> arr[i][j];
        }
    }

    mergesort(arr, 0, 0, m - 1, n - 1);
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
