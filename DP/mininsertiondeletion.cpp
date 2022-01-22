#include <bits/stdc++.h>
using namespace std;
/*
    logic : find LCS o/p=> s1.size()-lcs -> delete
    s2.size()-lcs ->insertion
*/
int main()
{
    string s1 = "heap";
    string s2 = "pea";

    int n = s1.size();
    int m = s2.size();

    int dp[n + 1][m + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout<<"delete"<<n - dp[n][m]<<" "<<"ins"<<m-dp[n][m];;
}