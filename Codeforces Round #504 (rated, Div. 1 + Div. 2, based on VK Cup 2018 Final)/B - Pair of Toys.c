#include <stdio.h>
 
int main(void) {
    unsigned long long int n,k;
    scanf("%llu%llu",&n,&k);
    unsigned long long int middle = (k>>1);
    if(n>=k)
        printf("%llu",middle-!(k%2));
    else if(n<middle)
        printf("0");
    else
        printf("%llu",n-middle);
	return 0;
}
