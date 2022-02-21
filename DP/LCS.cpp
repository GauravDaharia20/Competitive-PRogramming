#include<bits/stdc++.h>
using namespace std;
int LCS(string s1 , string s2, int n, int m, vector<vector<int>>&dp)
{
    if(n==0 || m==0)
    {
        return 0;
    }

    if(dp[n][m]!=-1)
    {
        return dp[n][m];
    }
    if(s1[n-1] == s2[m-1])
    {
        return dp[n][m] =  1+LCS(s1,s2,n-1,m-1,dp);
    }
    else{
        int a1 = LCS(s1,s2,n-1,m,dp);
        int a2 = LCS(s1,s2,n,m-1,dp);

        return dp[n][m]  = max(a1,a2);
    }
}
int main()
{
    string s1 = "bbbabcbbb";
    string s2 = "bbbcbabbb";
    //ara
    int n = s1.size(); int m = s2.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

    //cout<<LCS(s1,s2,s1.size(),s2.size(),dp);

    int dps[n+1][m+1];

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0)
            {
                dps[i][j] = 0;
            }

            else if(s1[i-1] == s2[j-1])
            {
                dps[i][j] = 1+dps[i-1][j-1];
            }
            else{
                dps[i][j] = max(dps[i-1][j] , dps[i][j-1]);
            }
        }
    }
    cout<<dps[n][m];



}