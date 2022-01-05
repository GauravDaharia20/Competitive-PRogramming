#include<bits/stdc++.h>
using namespace std;
vector<int>help(string s)
{
    vector<int>fq(26,0);
    for(auto i:s)
    {
        fq[i-'a']++;
    }
    return fq;
}
int main()
{
    vector<string>v = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>>ans;
    map<vector<int>,vector<string>>m;

    for(int i=0;i<v.size();i++)
    {
        vector<int>h = help(v[i]);
        m[h].push_back(v[i]);
    }
    for(auto i=m.begin();i!=m.end();i++)
    {  
    
        ans.push_back(i->second);
    }
   
    for(auto x:ans)
    {
        for(auto y : x)
        {
            cout<<y<<" ";
        }
        cout<<endl;
    }
}