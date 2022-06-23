#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>v = {1,3,4,2,2};
    vector<int>v1 = {1,3,12,3,1};
    
    cout<<v[0]<<" ";
    for(int i=1;i<v.size();i++)
    {
        v[i] = (v[i] | v[i-1]);
        cout<<v[i]<<" ";
    }
    cout<<endl;
    cout<<v1[0]<<" ";
    for(int i=1;i<v1.size();i++)
    {
        v1[i] = (v1[i] | v1[i-1]);
        cout<<v1[i]<<" ";
    }
    int ans = INT_MIN;
    for(int i=0;i<v1.size();i++)
    {
        int sum = 0;
        sum+=(v[i]+v1[i]);
        ans = max(ans,sum);

    }
    cout<<ans;
}