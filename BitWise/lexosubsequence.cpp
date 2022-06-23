#include<bits/stdc++.h>
using namespace std;
void lexosubs(string s,int n,vector<string>&v,int id=-1,string cur = "")
{
    if(id == n) return;
    if(!cur.empty())
    {   v.push_back(cur);
       // cout<<cur<<" ";
    }
    for(int i=id+1;i<n;i++)
    {
        cur+=s[i];
        lexosubs(s,n,v,i,cur);
        cur.erase(cur.size()-1);
    }
    return;
}
int main()
{
    string s = "aba";
    vector<string>v;
    lexosubs(s,s.size(),v);
    sort(v.begin(),v.end());
    for(auto i:v) cout<<i<<" ";
}