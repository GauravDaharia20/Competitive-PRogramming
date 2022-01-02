#include<bits/stdc++.h>
using namespace std;
int main()
{   
    vector<int>v={2,4,5,1,3};
    int n = v.size();
    pair<int,int>p[n];
    for(int i=0;i<v.size();i++)
    {
        p[i].first = v[i]; p[i].second = i;
    }
    sort(p,p+n);

    vector<int>vis(n,false);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(vis[i]==true or p[i].second == i)
        {
            continue;
        }
        int c = 0;
        int node = i;    
        while(!vis[node])
        {
            vis[node]=true;
            int nxt = p[node].second;
            node = nxt;
            c++;
        }
        ans+=(c-1);
    }
    cout<<ans;

}