#include<iostream>
using namespace std;
 
int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    int count[1005] = {0};
    int couples = 0;
    int sets = n/2 + n%2;
    while(n--)
    {
        scanf("%d",count);
        if(count[*count]%2)couples++;
        count[*count]++;
    }
    printf("%d\n",sets+couples);
    return 0;
}
