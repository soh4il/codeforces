#include <iostream>
using namespace std;
 
int n;
 
int main()
{
    string s;
    cin >> s;
    int q=0,aq=0,qaq=0;
    for(int i=s.length()-1;i>=0;i--)
    {
        if(s[i] == 'Q')
        {
            q++;
            qaq += aq;
        }
        if(s[i] == 'A')
            aq += q;
        
    }
    cout << qaq << endl;
    return 0;
}
