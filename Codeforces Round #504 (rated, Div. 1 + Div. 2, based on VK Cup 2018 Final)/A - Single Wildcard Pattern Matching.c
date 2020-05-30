#include <stdio.h>
 
int main(void) {
    int n,m;
    scanf("%d%d",&n,&m);
    char s[200002];
    char t[200002];
    scanf("%s%s",&s,&t);
    s[n] = '\0';t[m] ='\0';
    if(n>m+1)
    {
        printf("NO");
        return 0;
    }
    int index=-1;
    for(int i=0;i<n;i++)
    {
         if(s[i]!=t[i])
        {
            if(s[i] == '*')
            {
                index = i;
                break;
            }
            printf("NO");
            return 0;
        }
    }
    
    if(index < 0)
    {
        printf("%s",n==m?"YES":"NO");
        return 0;
    }
    for(int i=m-1,j=n-1;j>index;i--,j--)
    {
        if(s[j]!=t[i])
        {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
	return 0;
}
