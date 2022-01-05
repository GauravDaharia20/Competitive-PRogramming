#include<bits/stdc++.h>
using namespace std;
/*O(n)*/
int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>>p;
    while (n--)
    {
        /* code */
        int x,y;
        cin>>x>>y;
        p.push_back({x,y});
    }
    unordered_map<int,int>xc,yc;
    for(auto i:p)
    {
        xc[i.first]++;
        yc[i.second]++;
    }

    int cnt=0;
    for(auto i:p)
    {
        int x = i.first;
        int y = i.second;

        cnt+=( (xc[x]-1) * (yc[y]-1) );
    }
    cout<<cnt;
}