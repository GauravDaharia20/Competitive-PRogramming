#include<bits/stdc++.h>
using namespace std;
int getGp(vector<int>v,int ri)
{   int ans = 0;
    unordered_map<long ,long>r,l;
    for(auto i:v)
    {
        r[i]++;
        l[i] = 0;
    }

    for(int i=0;i<v.size();i++)
    {
        r[v[i]]--;

        if(v[i]%ri == 0)
        {
            long lf = v[i]/ri ;
            long rt = v[i]*ri;
            //long bt = v[i];

            ans+=(l[lf]*r[rt]);
        }
        l[v[i]]++;
    }

return ans;
}
int main()
{
    int n,r;
    cin>>n>>r;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<getGp(v,r);
}