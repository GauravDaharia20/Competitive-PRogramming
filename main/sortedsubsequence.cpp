#include<bits/stdc++.h>
using namespace std;
void subset(string s,string o,vector<string>&v)
{
    if(s.size()==0)
    {
        v.push_back(o);
        return;
    }
    char c = s[0];
    string update = s.substr(1);
    subset(update,o+c,v);
    subset(update,o,v);
}

bool comp(string s1,string s2)
{
    if(s1.length() == s2.length())
    {
        return s1 < s2;
    }
    return s1.length() < s2.length();
}
int main()
{
    string s;
    cin>>s;
    vector<string>v;
    string o = "";
    subset(s,o,v);
    sort(v.begin(),v.end(),comp);
    for(auto i:v)
    {
        cout<<i<<" ";
    }
}