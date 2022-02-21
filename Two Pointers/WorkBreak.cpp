#include <bits/stdc++.h>
using namespace std;
bool solve(string s, int id, vector<int> &dp, vector<string> &dict)
{
    if(id >=s.size()){
        return true;
    }

    if(dp[id]!=-1){
        return dp[id];
    }
    string tmp;
    for(int i=id;i<s.size();i++)
    {
        tmp+=s[i];
        if(find(dict.begin(),dict.end(),tmp) != dict.end() ){
               bool ans = solve(s,i+1,dp,dict);
               if(ans == true){
                   return dp[id]=true;
               } 
        }
    }
    return dp[id]=false;
}
int main()
{
    string s = "aaaaaaa";
    vector<string> dict = {"aaaa", "aaa"};
    vector<int> dp(s.length(), -1);
    cout << solve(s, 0, dp, dict);
}