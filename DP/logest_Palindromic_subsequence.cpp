#include<bits/stdc++.h>
int longestPalindromeSubsequence(string s)
{
    // Write your code here.
    string s1 = s;
    reverse(s.begin(),s.end());
    string s2 = s;
    int n = s.length();
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
            else if(s1[i-1]==s2[j-1]){
               dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
    }
    return dp[n][n];
}