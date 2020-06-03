#include <bits/stdc++.h>
using namespace std;
 
int arr[5],d;
 
int main(){
    for(int i=0;i<3;i++)scanf("%d",arr+i);
    scanf("%d",&d);
    sort(arr,arr+3);
    int duration = 0;
    int should_be = arr[1] - d;
    duration += max(0,arr[0] - should_be);
    should_be = arr[1] + d;
    duration += max(0,should_be - arr[2]);
    printf("%d\n",duration);
    return 0;
}
