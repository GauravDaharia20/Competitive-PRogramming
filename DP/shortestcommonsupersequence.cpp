#include<bits/stdc++.h>
using namespace std;
int main()
{
     string s1 = "abcefx";
     string s2 = "abcvgh";

     int n = s1.size(); int m = s2.size();
     int dp[n+1][m+1];

     for(int i=0;i<=n;i++)
     {
         for(int j=0;j<=m;j++)
         {
             if(i == 0 || j == 0)
             {
                 dp[i][j] = 0;
             }

             else if(s1[i-1] == s2[j-1])
             {
                 dp[i][j] = 1+dp[i-1][j-1];
             }
             else{
                 dp[i][j] = max( dp[i-1][j] , dp[i][j-1] );
             }
         }
     }

     cout<<n+m-dp[n][m];
}