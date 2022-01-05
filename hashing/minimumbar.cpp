#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s = "helloworldhi";
    set<string> st = {"world", "hi", "hello", "helloworld", "batman"};
    //  string s = "codingminutes";
    // set<string>st = {"coding","minutes","hours","s","code","cod","ing"};
    map<string, int> mp;
    int cc = 0;
    int cnt = 0;
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = i; j < s.length(); j++)
        {
            mp[s.substr(i, j)]++;
        }
    }
    for (auto i : mp)
    {
        string a = i.first;
        if (st.find(a) != st.end())
        {
            cc++;
            if (cc > 2)
                cnt++;
        }
    }
    cout << cnt - 1;
}