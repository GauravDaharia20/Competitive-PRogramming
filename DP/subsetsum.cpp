#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v = {2, 3, 6, 7};
    int s = 9;
    int n = v.size();

    int dp[n+1][s+1];

    for(int i=0;i<=n;i++)              /* n=> size of arr  and s=> sum so far*/
    {
        dp[i][0] = 1;
    }

    for(int i=1;i<=s;i++)
    {
        dp[0][i] = 0;
    }

    for(int i=1;i<=n;i++)   // cols=> size of arr
    {
        for(int j=1;j<=s;j++) // rows => sum for required arr
        {
            if(v[i-1] <=s)
            {
                dp[i][j] = dp[i][j-v[i-1]] || dp[i-1][j];  // (same as knapsack instead of max use=> ||)
            }
            else{
                    dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout<<dp[n][s];
    cout<<endl;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=s;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    
}