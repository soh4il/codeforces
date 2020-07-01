#include<bits/stdc++.h>
#define ll unsigned long long int
using namespace std;
 
int q,m,last2;
ll n,t;
int bits[100];
 
int main()
{
    scanf("%d",&q);
    while(q--)
    {
        scanf("%llu",&n);
        t = n;
        memset(bits,0,sizeof(bits));
        for(m=0,last2 = -1;t;t/=3,m++)
        {
            bits[m] = t%3;
            if(bits[m] == 2)
                last2 = m;
        }
         if(last2 == -1)printf("%llu\n",n);
         else {
            ll ans = 0;bool carry = 1;
            for(int i=last2+1;i<=m;i++)
            {
                if(!bits[i])
                {
                    if(carry)
                        ans += pow(3,i);
                    carry = 0;
                }
                else if(!carry)
                        ans += pow(3,i);
            }
            printf("%llu\n",ans);
        }
    }
    return 0;
}
