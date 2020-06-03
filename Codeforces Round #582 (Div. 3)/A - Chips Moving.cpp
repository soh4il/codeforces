#include <iostream>
using namespace std;
 
int main(){
    int n,num;
    cin >> n;
    int countOdd = 0,countEven = 0;
    for(int i=0;i<n;i++)
    {
    	cin >> num;
    	if(num%2)countOdd++;
    	else countEven++;
    }
    cout << min(countEven,countOdd) << endl;
    return 0;
}
