#include<bits/stdc++.h>
using namespace std;
/*

    logic is same as mcm a small change is to start i=0 and j=n-1.
*/
int dp[1001][1001];
bool check(string &s,int i,int j){

        if(i> j  || i==j){
            return true;
        }

        while (i<j)
        {
            /* code */
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
}
int countPartition(string s,int i,int j){
    if(i>=j){
        return 0;
    }

    if(check(s,i,j)==true){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans = INT_MAX;
    for(int k=i;k<=j-1;k++){
        int t = countPartition(s,i,k) + countPartition(s,k+1,j) + 1;
        //cout<<t<<" ";
        ans = min(ans,t);
    }
    return dp[i][j] =  ans;
}
int main(){
    memset(dp,-1,sizeof(dp));
    string s = "ababab";
    cout<<countPartition(s,0,s.size()-1);

}