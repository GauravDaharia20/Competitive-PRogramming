#include <bits/stdc++.h>
using namespace std;
int rodcut(vector<int> v, int n)
{
    // if(n == 0) return 0;
    // int ans = INT_MIN;
    // for(int i=0;i<n;i++)
    // {
    //     int cut = i+1;
    //     int currprice = v[i] + rodcut(v,n-cut);
    //     ans = max(ans,currprice);
    // }
    // return ans;

    // dp

    int dp[n + 1];
    dp[0] = 0;

    for (int len = 1; len <= n; len++)
    {
        int ans = INT_MIN;

        for (int i = 0; i < len; i++)
        {
            int cut = i + 1;
            int cp = v[i] + dp[len - cut];
            ans = max(ans, cp);
        }
        dp[len] = ans;
    }

    return dp[n];
}
int main()
{
    vector<int> v = {1, 5, 8, 9, 10, 17, 17, 20};
    cout << rodcut(v, v.size());
}