#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<char>> grid;
bool winright(int startx, int starty, int k, int m, char player)
{
    if (starty + k >= m)
        return false;
    while (starty < starty + k)
    {
        if (grid[startx][starty] != player)
            return false;
        starty++;
    }
    return true;
}

bool winleft(int startx, int starty, int k, int m, char player)
{
    if (starty - k + 1 <= 0)
        return false;
    while (starty > starty - k)
    {
        if (grid[startx][starty] != player)
            return false;
        starty--;
    }
    return true;
}

bool winup(int startx, int starty, int k, int n, char player)
{
    if (startx + k >= n)
        return false;
    while (startx < startx + k)
    {
        if (grid[startx][starty] != player)
            return false;
        startx++;
    }
    return true;
}

bool windown(int startx, int starty, int k, int n, char player)
{
    if (startx - k + 1 <= 0)
        return false;
    while (startx > startx - k)
    {
        if (grid[startx][starty] != player)
            return false;
        startx--;
    }
    return true;
}

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    ll turns = n * m;
    cout<<n<<" "<<m<<" "<<k<<" "<<turns;
    grid = vector<vector<char>>(n, vector<char>(m));
    bool onewins = false;
    char player;
    // bool onewins=;
    while (turns-- && !onewins)
    {

        int startx, starty;
        cin >> startx >> starty;
        startx=startx-1;starty=starty-1;

        if ((n * m - turns) % 2 == 0)
        {
            player = 'A';
        }
        else
        {
            player = 'B';
        }
        if (winright(startx, starty, k, m, player) || winleft(startx, starty, k, m, player) || winup(startx, starty, k, n, player) || windown(startx, starty, k, n, player))
        {
            onewins = true;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
        
    }
    cout<<endl<<turns<<" ";
    while(turns--)
    {
        int p,q;
        cin>>p>>q;
    }
    if(onewins)
        cout << player << endl;
    return;
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
