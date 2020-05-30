#include <stdio.h>
 
int main(void) {
    int n,k;
    scanf("%d%d",&n,&k);
    char s[200002];
    char t[200002];
    scanf("%s",&s);
    s[n] = '\0';
    int openBrackets,closeBrackets;
    openBrackets = closeBrackets = k >> 1;
    for(int i=0;i<n;i++)
    {
        if(s[i] == '(' && openBrackets)
        {
          printf("(");
          openBrackets--;
        }
        else if (s[i] == ')' && closeBrackets)
        {
          printf(")");
          closeBrackets--;
        }
        else if(!openBrackets && !closeBrackets)
            break;
    }
    
	return 0;
}
