#include<bits/stdc++.h>
using namespace std;
/*
    concept -> Either add element to knapsack or not add.
*/

int Knapsack(vector<int>wt,vector<int>val,int W,int n,vector<vector<int>>&dp){
    //base case

    if(n == 0 || W==0)
    {
        return 0;
    }
    if(dp[n][W]!=-1)
    {
        return dp[n][W];
    }
    if(wt[n-1] <=W)
    {
        int inc = val[n-1] + Knapsack(wt,val,W-wt[n-1],n-1,dp);
       // cout<<"inc"<<inc<<endl;
        int exc = Knapsack(wt,val,W,n-1,dp);
        //cout<<"exc"<<exc<<endl;
        return dp[n][W] = max(inc,exc);
    }
    else{
        return dp[n][W] = Knapsack(wt,val,W,n-1,dp);
    }
}
int main()
{
    vector<int>val = {2,5,6,3};
    vector<int>wt = {1,4,5,2};
    int W = 10;
    int n = val.size();
    vector<vector<int>>dp(val.size()+1,vector<int>(W+1,-1));
    cout<<Knapsack(wt,val,W,val.size(),dp);

    int t[n+1][W+1];

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=W;j++)
        {
            if(i==0 || j==0)
            {
                t[i][j] = 0;
            }

            else if(wt[i-1]<=j)
            {
                t[i][j] = max(t[i-1][j] , val[i-1]+t[i-1][j-wt[i-1]]);
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }

    cout<<t[n][W];    
    
}