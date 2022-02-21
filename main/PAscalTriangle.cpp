#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n = 2;
    vector<vector<int>>dp;
    dp.push_back({1});

    for(int i=1;i<n;i++)
    {   dp.push_back({1});
        for(int j=1;j<i;j++)
        {
            dp[i].push_back(dp[i-1][j-1] + dp[i-1][j]);
        }
        dp[i].push_back(1);
    }

    for(int i=0;i<n;i++){
        cout<<dp[n-1][i]<<" ";
    }
}