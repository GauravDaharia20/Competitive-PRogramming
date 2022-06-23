#include <bits/stdc++.h>
using namespace std;
int jumpRecur(int id, vector<int> &v, int k)
{
    if (id == 0)
        return 0;
    int ans = INT_MAX;

    for (int i = 1; i <= k; i++)
    {

        if (id - i >= 0)
        {

            int fs = jumpRecur(id - i, v, k) + abs(v[id] - v[id - i]);
            ans = min(fs, ans);
        }
    }

    return ans;
}

int jumpMemo(int id, vector<int> &v, int k, vector<int> &dp)
{
    if (id == 0)
        return 0;

    if (dp[id] != -1)
        return dp[id];
    int ans = INT_MAX;

    for (int i = 1; i <= k; i++)
    {

        if (id - i >= 0)
        {

            int fs = jumpMemo(id - i, v, k, dp) + abs(v[id] - v[id - i]);
            ans = min(fs, ans);
        }
    }

    return dp[id] = ans;
}

int jumpDP(int id,vector<int>&v,int k)
{       
        vector<int>dp(v.size()+1);
        dp[0] = 0;
        int ans = INT_MAX;
        for(int i=1;i<id;i++){
                for(int j=1;j<=k;j++){
                    
                    if(i-j >=0){
                       int jump = dp[i-j] + abs(v[id]-v[id-j]);
                       ans = min(ans,jump);
                    }
                    
                }
                dp[i] = ans;
                
        }
        return dp[id];
}
int main()
{

    /* minjump to reach K after having k steps*/

    vector<int> v = {10, 20, 30, 10};
    cout << jumpRecur(v.size(), v, 3) << endl;
    vector<int> dp(v.size() + 1, -1);
    jumpMemo(v.size(), v, 3, dp);
    cout<<dp[v.size()]<<endl;
    cout<<jumpDP(v.size(),v,3);
   // cout<<dp[v.size()-1]<<endl;
}