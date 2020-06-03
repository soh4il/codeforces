#include <bits/stdc++.h>
#define ll long long int
 
using namespace std;
 
int n,best_category = 0;;
char mp[] = {'D','A','C','B'};
 
int main(){
    scanf("%d",&n);
    for(int i=1;i<3;i++)if(mp[(n+i)%4] < mp[(n+best_category)%4])best_category = i;
    printf("%d %c\n",best_category,mp[(n+best_category)%4]);
    return 0;
}
