#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>v={50,4,10,8,30,100};
    int dp[v.size()] = {1};

    int l = 1;

    for(int i=1;i<v.size();i++)
    {
        //dp[i]=1;
        for(int j=0;j<i;j++)
        {
            if(v[j] < v[i])
            {
                dp[i] = max(dp[i],1+dp[j]);
                l = max(l,dp[i]);
            }
        }
    }
    cout<<l;
    
}