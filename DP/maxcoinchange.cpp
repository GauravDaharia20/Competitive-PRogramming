#include<bits/stdc++.h>
using namespace std;
/*
    question : maximum number (ways)=>add to make change
    logic : unbounded knapsack.
*/
int main()
{
        vector<int>v = {1,2,3};  /*11111, 1112, 221,122,32*/
        int sum = 5;
        int n = v.size();
        int dp[n+1][sum+1];

        for(int i=0;i<=n;i++)
        {
            dp[i][0] = 1;
        }

        for(int i=1;i<=sum;i++)
        {
            dp[0][i] = 0;
        }


        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(v[i-1] <= j)
                {
                    dp[i][j] = (dp[i-1][j] +dp[i][j-v[i-1]]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=sum;j++)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
}