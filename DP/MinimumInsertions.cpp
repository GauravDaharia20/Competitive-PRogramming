#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s = "dad";
    string st = s;
    reverse(s.begin(),s.end());
    string t = s;
   // cout<<st<<" "<<t;
    vector<vector<int>>dp(s.size()+1,vector<int>(t.size()+1,0));
    for(int i=0;i<=s.size();i++){
        for(int j=0;j<=t.size();j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
            else if(st[i-1]==t[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
    }
    cout<<s.size() - dp[s.size()][t.size()];
}