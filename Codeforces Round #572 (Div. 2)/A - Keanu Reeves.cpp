#include<iostream>
 
using namespace std;
 
int main()
{
    int n;
    char str[105];
    int count[5] = {0};
    scanf("%d%s",&n,str);
    for(int i=0;i<n;i++)
        count[str[i]-'0']++;
    if(count[0] != count[1])
        printf("1\n%s\n", str);
    else
        {
            printf("2\n%c ",str[0]);
            for(int i=1;i<n;i++)
                printf("%c", str[i]);
            printf("\n");
        }
    return 0;
}
