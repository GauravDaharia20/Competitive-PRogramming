#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>v={0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int>l(v.size(),0),r(v.size(),0);
    l[0]=v[0]; r[v.size()-1] = v[v.size()-1];
    for(int i=1;i<v.size();i++)
    {
        l[i]=max(v[i],l[i-1]);
        r[v.size()-i-1] = max(r[v.size()-i],v[v.size()-i-1]);
        
    }

    

    int s=0;
    for(int i=0;i<v.size();i++)
    {
       int t = min(l[i],r[i])-v[i];
      s+=t;
    }
    cout<<s;
}