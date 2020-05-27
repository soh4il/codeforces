#include <bits/stdc++.h>
using namespace std;
 
string grid[5];
bool xWins,oWins;
int cntx,cnto,cnt;
 
bool bothWin()
{
    xWins = oWins = 0;
    for(int i=0;i<3;i++)
    {
        if(grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i])
        {
            if(grid[0][i] == 'X')xWins = 1;
            if(grid[0][i] == '0')oWins = 1;
        }
        if(grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2])
        {
            if(grid[i][0] == 'X')xWins = 1;
            if(grid[i][0] == '0')oWins = 1;
        }
    }
    if(grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2])
    {
        if(grid[0][0] == 'X')xWins = 1;
        if(grid[0][0] == '0')oWins = 1;
    }
    if(grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0])
    {
        if(grid[0][2] == 'X')xWins = 1;
        if(grid[0][2] == '0')oWins = 1;
    }
    return xWins && oWins;
}
 
bool illegalCount()
{
    cntx = cnto = cnt = 0;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
        {
            if(grid[i][j] == 'X')cntx++;
            else if(grid[i][j] == '0')cnto++;
            else cnt++;
        }
    return cntx < cnto || abs(cntx - cnto) > 1 || (oWins&&cntx > cnto) || (xWins&&cntx == cnto);
}
 
int main()
{
    //Presetup:
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //-------------------------------
    for(int i=0;i<3;i++)cin >> grid[i];
    if(bothWin() || illegalCount()) return cout << "illegal\n",0;
    if(xWins) return cout << "the first player won\n",0;
    if(oWins) return cout << "the second player won\n",0;
    if(!cnt) return cout << "draw\n",0;
    if(cntx == cnto)return cout << "first\n",0;
    if(cntx > cnto)return cout << "second\n",0;
    assert(false);
    return 0;
}
