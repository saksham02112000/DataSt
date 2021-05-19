#include<bits/stdc++.h>
using namespace std;
int X=0,O=0,s=0;
bool isValid() {
    if(X-O==0 || X-O==1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool winningchance(char arr[][3], int* num)
{
    bool xwin=false,owin=false;
    for (int i = 0; i < 3; ++i) {
        if (arr[i][0] == 'X' && arr[i][1] == 'X' && arr[i][2] == 'X') {
            xwin = true;
        }
        if (arr[i][0] == 'O' && arr[i][1] == 'O' && arr[i][2] == 'O') {
            owin = true;
        }
        if (arr[0][i] == 'O' && arr[1][i] == 'O' && arr[2][i] == 'O') {
            owin = true;
        }
        if (arr[0][i] == 'X' && arr[1][i] == 'X' && arr[2][i] == 'X') {
            xwin = true;
        }
    }
        if(arr[0][0]=='O' && arr[1][1]=='O' && arr[2][2]=='O')
        {

            owin=true;
        }
        if(arr[0][0]=='X' && arr[1][1]=='X' && arr[2][2]=='X')
        {
            xwin=true;
        }
        if(arr[2][0]=='O' && arr[1][1]=='O' && arr[0][2]=='O')
        {
            owin=true;
        }
        if(arr[2][0]=='X' && arr[1][1]=='X' && arr[0][2]=='X')
        {
            xwin=true;
        }

    if(xwin && owin)
    {
        return false;
    }
    if(xwin) {
        if (X - O == 1) {
            *num=1;
            return true;
        }
    }
    if(owin)
    {
        if(X-O==0) {
            *num=1;
            return true;
        }
    }
    if(s==0)
    {
        *num=1;
        return true;
    }
    if(!xwin && !owin)
    {
        *num=2;
        return true;
    }

return false;
}

int main()
{
    int m;
    cin>>m;
    while(m--)
    {
        X=0;
        O=0;
        s=0;
    int num=-1;
    char arr[3][3];
    for (auto & i : arr) {
        for (char & j : i) {
            cin>>j;
            if(j=='X')
            {
                X++;
            }
            if(j=='O') {
                O++;
            }
            if(j=='_')
            {
                s++;
            }
        }
    }
//    for(auto & i : arr)
//    {
//        for (char j : i) {
//            cout<<j;
//        }cout<<endl;
//    }

    if(isValid())
    {
//        cout<<"f"<<endl;
        if(winningchance(arr, &num))
        {
            cout<<num<<endl;
        }
        else {
            cout << 3 << endl;
        }
    }
    else
    {
        cout<<3<<endl;
    }
    }
    return 0;
}