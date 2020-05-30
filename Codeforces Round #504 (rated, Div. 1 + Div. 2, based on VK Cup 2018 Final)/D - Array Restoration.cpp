#include <bits/stdc++.h>
using namespace std;
 
int n,q;
int arr[200005];
 
int main()
{
    //Presetup:
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //-------------------------------
    scanf("%d%d",&n,&q);
    for(int i=0;i<n;i++)scanf("%d",&arr[i]);
    stack<int> s;
    bitset<200005> cannot;
    bool zeroExist = 0,qExist = 0;
    cannot.reset();
    for(int i=0;i<n;i++)
    {
        if(cannot.test(arr[i]))return 0&printf("NO\n");
        if(!arr[i])zeroExist = 1;
        else{
            if(arr[i] == q)qExist = 1;
            if(s.empty() || arr[i] > s.top())s.push(arr[i]);
            else{
                while(!s.empty() && arr[i] < s.top()){
                    cannot.set(s.top());
                    s.pop();
                }
            }    
        }
    }
    if(!zeroExist && !qExist)return 0&printf("NO\n");
    printf("YES\n");
    for(int i=0;i<n;i++)
    {
        if(!arr[i]){
            if(!qExist)
            {
                arr[i] = q;
                qExist = 1;
            }else
                arr[i] = i?arr[i-1]:1;
        }
        
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}
