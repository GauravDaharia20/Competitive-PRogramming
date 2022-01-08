#include <bits/stdc++.h>
using namespace std;
/*
    Q=> find equal partition subset,
    A=> find only one subset which is divible in two parts.
*/
int subsets(vector<int> v , int s, int n)
{
    int dp[n+1][s+1];
    for(int i=0;i<=n;i++)
    {
        dp[i][0] = 1;
    }

    for(int i=1;i<=s;i++)
    {
        dp[0][i] = 0;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=s;j++)
        {
            if(v[i-1] <=s)
            {
                dp[i][j] = dp[i-1][j] || dp[i][j-v[i-1]];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][s];
}
int main()
{
    vector<int> v = {2, 3, 6,1};
    int sum = accumulate(v.begin(), v.end(), 0);
    if (sum % 2 != 0)
        cout << "false";
    else
    {
        int n = v.size();
        int s = sum / 2;

        cout<<subsets(v,s,n);
    }
}