#include <bits/stdc++.h>
using namespace std;
int calculate(int day, int last, vector<vector<int>> &v, vector<vector<int>> &dp1)
{

    if (day == 0)
    {
        int maxi = 0;
        for (int i = 0; i < 3; i++)
        {
            if (i != last)
            {
                maxi = max(maxi, v[0][i]);
            }
        }
        return maxi;
    }
    int maxi = 0;
    if (dp1[day][last] != -1)
    {
        return dp1[day][last];
    }
    for (int i = 0; i < 3; i++)
    {
        if (i != last)
        {

            int t = v[day][i] + calculate(day - 1, i, v, dp1);
            maxi = max(maxi, t);
        }
    }
    return dp1[day][last] = maxi;
}
int help(int n, vector<vector<int>> &v, vector<vector<int>> &dp1)
{ // vector<vector<int>>dp(n,vector<int>(4,-1));
    return calculate(n - 1, 3, v, dp1);
}

int main()
{
    vector<vector<int>> v = {
        {1, 2, 5}, {3, 1, 1}, {3, 3, 3}};
    int n = v.size();
    // vector<vector<int>> dp1(n, vector<int>(4, -1));
    // help(n, v, dp1);

    vector<vector<int>> dp(n, vector<int>(4, 0));
    dp[0][0] = max(v[0][1], v[0][2]);
    dp[0][1] = max(v[0][0], v[0][2]);
    dp[0][2] = max(v[0][1], v[0][0]);
    dp[0][3] = max({v[0][1], v[0][2], v[0][0]});

    for (int day = 1; day < n; day++)
    {
        for (int last = 0; last < 4; last++)
        {
            dp[day][last] = 0;
            for (int tsk = 0; tsk < 3; tsk++)
            {

                if (tsk != last)
                {
                    int res = v[day][tsk] + dp[day - 1][tsk];
                    dp[day][last] = max(dp[day][last], res);
                }
            }
        }
    }
    cout << dp[n - 1][3];
}