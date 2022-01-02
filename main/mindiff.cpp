#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>v1={23,5,10,17,30};
    vector<int>v2={26,134,135,14,19};
    set<int>st = {0,1,2};
    //sort(v2.begin(),v2.end(),greater<int>());
    pair<int,int>p;
    //int ans = INT_MAX;
    for(auto i:v1)
    {
        for(auto j:v2)
        {
            //cout<<i<<" "<<j<<endl;
            if(st.find(abs(i-j))!=st.end() )
            {
                p.first = i;
                p.second = j;
            }
        }
    }
    cout<<p.first<<" "<<p.second;
}