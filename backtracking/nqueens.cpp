#include<iostream>
using namespace std;
bool isSafe(int** arr, int x,int y, int n)
{
    for(int row=0;row<n;row++)
    {
        if(arr[row][y]==1)
        {
            return false;
        }
    }
    int row=x;
    int column=y;
    while(row>=0 && column>=0)
    {
        if(arr[row][column]==1)
        {
            return false;
        }
        row--;
        column--;
    }
    row=x;
    column=y;
    while(row>=0 && column<n)
    {
        if(arr[row][column]==1)
        {
            return false;
        }
        row--;
        column++;
    }
    return true;
}

bool nqueen(int** arr, int x, int n)
{
    if(x>=n)
    {
        return true;
    }
    for (int i = 0; i < n; i++)
    {
        if(isSafe(arr,x,i,n))
        {
            arr[x][i]=1;
            if(nqueen(arr,x+1,n))
            {
                return true;
            }
            arr[x][i]=0;
        }
    }
    return false;
}

int main()
{
    int n=4;
    // cin>>n;

    int** arr=new int*[n];
    for (int i = 0; i < n; i++)
    {
        arr[i]=new int[n];
        for (int j=0;j<n;j++)
        {
            arr[i][j]=0;
        }
    }
    if(nqueen(arr,0,n))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}