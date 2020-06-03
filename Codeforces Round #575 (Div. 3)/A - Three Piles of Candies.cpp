#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int t;
ll a,b,c;

int main(){
    scanf("%d",&t);
    while(t--)
    {
       scanf("%lld%lld%lld",&a,&b,&c);
       printf("%lld\n",(a+b+c)/2); 
    }
   return 0;
}
