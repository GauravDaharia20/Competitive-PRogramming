#include<bits/stdc++.h>
using namespace std;
int main()
{
    /*
        find maximum adjacent sum
    */

   vector<int>v = {6,10,12,7,8,14};
   int dp[v.size()] = {0};

   dp[0] = v[0]; dp[1] = max(dp[0],dp[1]);

   for(int i=2;i<=v.size();i++)
   {
       int a1 = dp[i-1];
       int a2 = v[i] + dp[i-2];
       dp[i] = max(a1,a2);
   }
   cout<<dp[v.size()-1];

}