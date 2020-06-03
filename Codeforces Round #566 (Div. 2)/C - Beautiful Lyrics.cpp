#include <bits/stdc++.h>
using namespace std;
 
const set<char> vowel = {'a','e','i','o','u'};
 
int t=1,n;
vector<string> words;
map<pair<int,char>,set<int>> sameNoSameChar;
map<int,set<int>> sameNo;
vector<pair<int,int>> samesameCouple;
vector<pair<int,int>> sameCouple;
 
void preprocess(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
 
void input()
{
    cin >> n;
    words.resize(n);
    for(int i=0;i<n;i++)cin >> words[i];
}
 
int solve()
{
    for(int i=0;i<n;i++)
    {
        int cnt = 0,last;
        for(char c:words[i])if(vowel.find(c)!=vowel.end())
        {
            cnt++;
            last = c;
        }        
        if(cnt)sameNoSameChar[make_pair(cnt,last)].insert(i);
        sameNo[cnt].insert(i);
    }
    for(auto it = sameNoSameChar.begin();it!=sameNoSameChar.end();it++)
    {
        vector<int> couple;
        for(auto it2 = it->second.begin();it2!=it->second.end();it2++)
        {
            couple.push_back(*it2);
            if(couple.size() == 2){
                samesameCouple.push_back(make_pair(couple[0],couple[1]));
                sameNo[it->first.first].erase(couple[0]);
                sameNo[it->first.first].erase(couple[1]);
                couple.clear();
            }
        }
    }
 
    for(auto it = sameNo.begin();it!=sameNo.end();it++)
    {
        vector<int> couple;
        for(auto it2 = it->second.begin();it2!=it->second.end();it2++)
        {
            couple.push_back(*it2);
            if(couple.size() == 2)
            {
                sameCouple.push_back(make_pair(couple[0],couple[1]));
                couple.clear();
            }
        }
    }
 
    while(samesameCouple.size() > sameCouple.size()){
        sameCouple.push_back(samesameCouple.back());
        samesameCouple.pop_back();
    }
 
    // Debugging
    //----------------------------------------------------------------------------------------------
    // for(int i=0;i<samesameCouple.size();i++){
    //     cout << words[samesameCouple[i].first] << " " << words[samesameCouple[i].second] << endl;
    // }
    // cout << "-------------------------------------------------------------\n";
    // for(int i=0;i<sameCouple.size();i++){
    //     cout << words[sameCouple[i].first] << " " << words[sameCouple[i].second] << endl;
    // }
 
    int m = samesameCouple.size();
    cout << m << endl;
    for(int i=0;i<m;i++)
    {
        cout << words[sameCouple[i].first] << " " << words[samesameCouple[i].first] << endl;
        cout << words[sameCouple[i].second] << " " << words[samesameCouple[i].second] << endl;
    }
 
}
 
int main()
{
    preprocess();
    while(t--)
    {
        input();
        solve();
    }
    return 0;
}
