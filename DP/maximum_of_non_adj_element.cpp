#include<bits/stdc++.h>
using namespace std;
int adj_Sum(int id,int *a,vector<int>&memo){

        if(id == 0) return a[id];

        if( id < 0) return 0;

        if(memo[id]!=-1) return memo[id];

        int pick = a[id] + adj_Sum(id-2,a,memo);
        int notpick = 0+adj_Sum(id-1,a,memo);

        return memo[id]= max(pick,notpick);


}

int adj_Sum_dp(int *a,int n){
    // int dp[n][2];
    // if(n == 1) return a[0];

    // dp[0][0] = 0;
    // dp[0][1] = a[0];

    // for(int i=1;i<n;i++){
    //     dp[i][1] = dp[i-1][0] + a[i];
    //     dp[i][0] = max(dp[i-1][1],dp[i-1][0]);
    // }
    // return max(dp[n-1][0],dp[n-1][1]);
    
    int prev = a[0];
    int prev2 = 0;
    //int curi;
    for(int i=1;i<n;i++){
        int take = a[i];
        if(i > 1){
            take += prev2;
        }
        int ntake = 0 + prev;
        int curi = max(take,ntake);
        prev2 = prev;
        prev = curi;
    }

    return prev;
}
int main(){
    int a[] = {1,2,4};
    //vector<int>memo(4,-1);
    //cout<<adj_Sum(3,a,memo);
    // for(int i=0;i<memo.size();i++) {
    //     cout<<i<<" "<<memo[i]<<endl;
    //     }
    //cout<<memo[memo.size()-1];


    cout<<adj_Sum_dp(a,3);



    
}