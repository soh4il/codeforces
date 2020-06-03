#include<iostream>

using namespace std;

int main()
{
    int h,w;
    cin >> h >> w;
    char matrix[505][505];
    bool isStar[505][505] = {0};
    bool foundCenter = false;
    for(int i=0;i<h;i++)
        scanf("%s",matrix[i]);
    
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            if(matrix[i][j] == '*')
            {
                
                if(i>0   && matrix[i-1][j] == '*')
                if(j>0   && matrix[i][j-1] == '*')
                if(i<h-1 && matrix[i+1][j] == '*')
                if(j<w-1 && matrix[i][j+1] == '*')
                {
                    isStar[i][j] = true;
                    for(int x=i-1;x>=0;x--)
                        if(matrix[x][j] == '*')
                            isStar[x][j] = true;
                        else
                            break;
                    for(int x=j-1;x>=0;x--)
                        if(matrix[i][x] == '*')
                            isStar[i][x] = true;
                        else
                            break;
                    for(int x=i+1;x<h;x++)
                        if(matrix[x][j] == '*')
                            isStar[x][j] = true;
                        else
                            break;
                    for(int x=j+1;x<w;x++)
                        if(matrix[i][x] == '*')
                            isStar[i][x] = true;
                        else
                            break;
                    foundCenter = true;
                    goto out;
                }
            }
        }
    }
    out:
    if(!foundCenter)
    {
        cout << "NO\n";
        return 0;
    }
    
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            if(matrix[i][j] == '*')
            {
                if(!isStar[i][j])
                {
                    cout << "NO\n";
                    return 0;
                }
            }
        }
    }
    
    cout << "YES\n";
    
    
    return 0;
}
