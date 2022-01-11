/* count number of subset of given array
   logic : same as subset sum just try to find the all sumset who sum is equal to given sum.


*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>v = {9,1,2,11};
    int sum = 2;
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
            if(v[i-1] <=j)
            {
                dp[i][j] = dp[i-1][j] + dp[i][j-v[i-1]];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout<<dp[n][sum]<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<sum;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

}