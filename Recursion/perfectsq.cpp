#include<bits/stdc++.h>
using namespace std;
vector<int>dp(10001,-1);
int perfect(int n){
    if(n == 0) return 0;
    if(n == 1 ) return 1;
    if(dp[n] !=-1){
        return dp[n];
    }
    int ans = INT_MAX;
    for(int i=1;i*i<=n;i++)
    {
            ans = min(ans , 1+perfect(n-i*i));
    }
    return dp[n] = ans;
}
int main(){
    int n = 12;
    cout<<perfect(n);

    vector<int>f = {1,2,2,3,4};
    unordered_map<int, int> mp;
    for(int i=0;i<f.size();i++)
    {   
        mp[f[i]] = i;
    }

    for(int i=0;i<f.size();i++)
    {   
        cout<<f[i]<<" "<<mp[f[i]]<<endl;
    }
}