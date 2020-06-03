#include<iostream>
#include<cmath>
using namespace std;
 
int main() {
    double n,k;
    scanf("%lf%lf",&n,&k);
    double root2,a,b,c,root;
    a = 1; b = -(2*n+3); c = n*n+n-2*k;
    root = sqrt(b*b - 4.0 * a * c);
    root2 = -0.5 * (root +b)/a;
    printf("%ld\n",(long)root2);
    return 0;
}
