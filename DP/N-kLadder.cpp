#include<bits/stdc++.h>
using namespace std;
// O(n^k)
int countWay(int n,int k)
{   
    if(n == 0) return 1;

    if(n < 0) return 0;

    int ans = 0;

    for(int i=1;i<=k;i++)
    {
        ans+=countWay(n-i,k);
    }
    return ans;
}
// O(n*k)
int countWayTD(int n,int k, int *dp)
{   
    if(n == 0) return 1;

    if(n < 0) return 0;

    if(dp[n]!=0)
    {
        return dp[n];
    }
    int ans = 0;

    for(int i=1;i<=k;i++)
    {
        ans+=countWay(n-i,k);
    }
    return dp[n] = ans;
}
//O(n+k)
int countWayBU(int n,int k)
{   
    int dp[n+1]={0};
    dp[0] = 1;
    dp[1] = 1;
   

    for(int i=2;i<=k;i++) // 2*dp[i-1] - dp[i-k-1];
    {
       dp[i] = 2*dp[i-1] ;
    }
    for(int i=k+1;i<=n;i++)
    {
        dp[i] = 2*dp[i-1] - dp[i-k-1];
    }
    return dp[n];
}
int main()
{
    int n,k;
    cin>>n>>k;
    int dp[n+1]={0};
    cout<<countWayBU(n,k);
}