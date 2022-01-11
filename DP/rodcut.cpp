#include <bits/stdc++.h>
using namespace std;
int rodcut(vector<int> v, int n)
{
    // // if(n == 0) return 0;
    // // int ans = INT_MIN;
    // // for(int i=0;i<n;i++)
    // // {
    // //     int cut = i+1;
    // //     int currprice = v[i] + rodcut(v,n-cut);
    // //     ans = max(ans,currprice);
    // // }
    // // return ans;

    // // dp

    // int dp[n + 1];
    // dp[0] = 0;

    // for (int len = 1; len <= n; len++)
    // {
    //     int ans = INT_MIN;

    //     for (int i = 0; i < len; i++)
    //     {
    //         int cut = i + 1;
    //         int cp = v[i] + dp[len - cut];
    //         ans = max(ans, cp);
    //     }
    //     dp[len] = ans;
    // }

    // return dp[n];


    return 0;
}
int main()
{
    vector<int> v = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = 8;
    int dp[n+1][n+1];
    for(int i=0;i<=n;i++)
    {
        dp[i][0] = 0;
    }

    for(int i=0;i<=n;i++)
    {
        dp[0][i] = 0;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(v[i-1] <=n)
            {
                dp[i][j] = max(v[i-1] + dp[i][j-v[i-1]] , dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}