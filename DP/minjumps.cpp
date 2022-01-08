#include<bits/stdc++.h>
using namespace std;
int minjumps(vector<int>v,vector<int>dp,int n,int i)
{
    //base case 

    if(i == n-1)
    {
        return 0;
    }

    if(i>=n)
    {
        return INT_MAX;
    }

    // recur case

    if(dp[i]!=0)
    {
        return dp[i];
    }

    int mxstep = v[i];
    int step = INT_MAX;

    for(int jumps = 1;jumps<=mxstep;jumps++)
    {
        int nxtjump = i+jumps;
        int sp = minjumps(v,dp,n,nxtjump);
        if(sp!=INT_MAX)
        {
            step = min(step,sp+1);
        }
    }
    return dp[i] = step;
}
int main()
{
    vector<int>v= {3,4,2,1,2,3,7,1,1,3};
    vector<int>dp(v.size(),0);

    cout<<minjumps(v,dp,v.size(),0);
}