#include<bits/stdc++.h>
using namespace std;
// min step for frog to reach end.
int main()
{
    vector<int>v = {10,30,40,20};
    int dp[v.size()] = {0};

    dp[0] = 0;
    dp[1] = abs(dp[0]-dp[1]);

    for(int i=1;i<=v.size();i++)
    {
        int onestepback = dp[i-1] + abs(v[i-1] - v[i]); // either take one step back or two step back
        int twostepback =dp[i-2] + abs(v[i-2] - v[i]);

        dp[i] = min(onestepback,twostepback);
    }
    cout<<dp[v.size()-1];

}