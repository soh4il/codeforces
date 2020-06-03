#include <bits/stdc++.h>
using namespace std;
 
int n;
char s[1000006],t[1000006];
 
bool yes()
{
    vector<pair<char,int>> str1,str2;
    int slen = strlen(s),tlen = strlen(t);
    char curr = 0;
    for(int i=0,cnt = 0;i<=slen;i++)
    {
        if(s[i] != curr){
            if(curr)str1.push_back(make_pair(curr,cnt));
            curr = s[i];
            cnt = 1;
        }else cnt++;
    }
    
    curr = 0;
    for(int i=0,cnt=0;i<=tlen;i++)
    {
        if(t[i] != curr){
            if(curr)str2.push_back(make_pair(curr,cnt));
            curr = t[i];
            cnt = 1;
        }else cnt++;
    }
    if(str1.size() != str2.size())return 0;
    for(int i=0;i<str1.size();i++)
        if(str1[i].first != str2[i].first || str1[i].second > str2[i].second)
            return 0;
    return 1;
}
 
int main(){
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s%s",s,t);
        puts(yes()?"YES":"NO");
    }
    return 0;
}
