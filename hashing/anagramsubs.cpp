#include<bits/stdc++.h>
using namespace std;
vector<int>frequency(string s,int i,int j){

    vector<int>freq(26,0);

    for(int k = i;k<=j;k++)
    {
        freq[s[k]-'a']++;
    }

    return freq;

}
int countsubs(string s)
{
    map<vector<int>,int>m;
    int ans = 0;

    for(int i=0;i<s.length();i++)
    {
        for(int j = i;j<s.length();j++)
        {
            vector<int>f = frequency(s,i,j);
            m[f]++;
        }
    }

    for(auto i=m.begin();i!=m.end();i++)
    {
        if(i->second >=2)
        {   int f = i->second;
            int a = (f)*(f-1)/2;
            ans+=(a);
        }
    }
    return ans;
}
int main()
{
    string s;
    cin>>s;
    cout<<countsubs(s);
}