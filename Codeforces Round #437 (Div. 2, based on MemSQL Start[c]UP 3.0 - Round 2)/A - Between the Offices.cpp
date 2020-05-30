#include <bits/stdc++.h>
using namespace std;
 
int n,sf,fs;
char str[102];
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //--------------------------
    scanf("%d%s",&n,str);
    sf = fs = 0;
    for(int i=1;i<n;i++){
        if(str[i] == 'F' && str[i-1] == 'S')sf++;
        if(str[i] == 'S' && str[i-1] == 'F')fs++;
    }
    printf("%s\n",sf>fs?"YES":"NO");
    return 0;
}
