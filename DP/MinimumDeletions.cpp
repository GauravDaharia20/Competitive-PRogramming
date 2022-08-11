#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s = "aabbbb";
    int n = s.size();
    int dp[n];
    int maxi = -1;
    int i,j,la=0;int prb=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='a'){
            la++;
            dp[i] = la;
            maxi = max(dp[i],maxi);
        }
        if(s[i]=='b'){  
            dp[i] = max(la,prb)+1;
            maxi = max(dp[i],maxi);
            prb = dp[i];

        }
    }
    for(int i=0;i<n;i++){
        cout<<dp[i]<<" ";
    }
    cout<<n-maxi;
}