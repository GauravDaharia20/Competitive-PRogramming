#include<bits/stdc++.h>
using namespace std;
/*
probelm link:- https://www.codingninjas.com/codestudio/problems/number-of-longest-increasing-subsequence_3751627?leftPanelTab=0
*/
int main()
{
    vector<int>arr = {50,3,90,60,80};
    int n = arr.size();
    int ans = 1;
    vector<int>dp(n,1) , cnt(n,1);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[i] > arr[j] && 1+dp[j] > dp[i]){
                dp[i] = 1 + dp[j];
                cnt[i] = cnt[j];
            }
            else if(arr[i] > arr[j] && 1+dp[j] == dp[i]){
                cnt[i]+=cnt[j];
            }
        }
        ans = max(ans,dp[i]);
    }
    // for(auto i:dp){
    //     cout<<i<<" ";
    // }
    // cout<<endl;
    int count = 0;
    for(int i=0;i<n;i++){
        if(dp[i]==ans){
            count+=cnt[i];
        }
        //cout<<i<<" ";
    }
    cout<<count;
}