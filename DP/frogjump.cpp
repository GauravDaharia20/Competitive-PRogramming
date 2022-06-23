#include <bits/stdc++.h>
using namespace std;
int f(int n,vector<int>&heights){
    if (n == 0)
        return 0;
    
    int l = f(n - 1, heights) + abs(heights[n] - heights[n - 1]);
    int r = INT_MAX;
    if (n > 1)
    {
        r = f(n - 2, heights) + abs(heights[n] - heights[n - 2]);
    }

    return min(l,r);
}
int frogJump(int n, vector<int> &heights)
{
    // Write your code here
    return f(n-1,heights);
}

int frogJumpMemo(int n,vector<int>& v,vector<int>&dp){

    if(n==0) return 0;
    if(dp[n]!=-1) return dp[n];

    int left = frogJumpMemo(n-1,v,dp) + abs(v[n]-v[n-1]);
    int right = INT_MAX;
    if(n > 1) right=frogJumpMemo(n-2,v,dp) + abs(v[n]-v[n-2]);

    return dp[n]=min(left,right);

}

int frogJumpDp(int n,vector<int>v){

    vector<int>dp(n);
    dp[0]=0;
    for(int i=1;i<n;i++){

        int fs = dp[i-1]+abs(v[i]-v[i-1]);
        int ss=INT_MAX;
        if(i > 1){
            ss = dp[i-2] + abs(v[i]-v[i-2]);
        }
        dp[i] = min(fs,ss);
    }
    return dp[n-1];

}

int main()
{

    /*There is a frog on the 1st step of an N stairs long staircase.
    The frog wants to reach the Nth stair. HEIGHT[i] is the height of the (i+1)th stair.
    If Frog jumps from ith to jth stair, the energy lost in the jump is given by |HEIGHT[i-1] - HEIGHT[j-1] |.
    In the Frog is on ith staircase, he can jump either to (i+1)th stair or to (i+2)th stair.
    Your task is to find the minimum total energy used by the frog to reach from 1st stair to Nth stair.*/

    vector<int> v = {10, 20, 30, 10};
    vector<int>dp(v.size()+1,-1);
    cout<<frogJump(v.size(), v)<<endl;
    frogJumpMemo(v.size(), v,dp);
    cout<<dp[v.size()-1]<<endl;
    cout<<frogJumpDp(v.size(),v);
   
    
}