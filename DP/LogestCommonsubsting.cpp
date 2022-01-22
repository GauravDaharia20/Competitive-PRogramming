#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s1 = "abcdef";
    string s2 = "abxef";
    //aa, b, gh
    int n = s1.size(); int m = s2.size();
   // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

   

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
                dps[i][j] = 0;
            }
        }
    }
    cout<<dps[n][m];



}