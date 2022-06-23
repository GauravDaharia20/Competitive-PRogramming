/*Given a ‘N’ * ’M’ maze with obstacles, count and return the number of unique paths to reach the right-bottom cell from the top-left cell. 
 A cell in the given maze has a value '-1' if it is a blockage or dead-end, else 0.
 From a given cell, we are allowed to move to cells (i+1, j) and (i, j+1) only. 
 Since the answer can be large, print it modulo 10^9 + 7.*/

 #include<bits/stdc++.h>
 using namespace std;
//  int waysCount(int i,int j,vector<vector<int>>grid,vector<vector<int>>&dp){
//     if(i==0 && j==0) return 1;

//     if(i < 0 || j < 0) return 0;

//     if(i >=0 && j >=0 && grid[i][j]==-1) return 0;

//     if(dp[i][j]!=-1) return dp[i][j];
//     int up = waysCount(i-1,j,grid,dp);
//     int left = waysCount(i,j-1,grid,dp);

//     return dp[i][j] = (up+left)%1000000007;
//  }
 int main(){
    int m = 3; int n = 3;
    vector<vector<int>>grid(m,vector<int>(n));
    grid={
        {0,0,0},
        {0,-1,0},
        {0,0,0}
    };
    vector<vector<int>>dp(m,vector<int>(n,0));
    // cout<<waysCount(m-1,n-1,grid,dp);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++){
            if(i==0 && j == 0){
                dp[i][j] = 1;
            }
            else if(grid[i][j]==-1){
                dp[i][j] = 0;
            }
            else{
                int up = 0; int left = 0;
                if(i>0) up = dp[i-1][j];
                if(j > 0) left = dp[i][j-1];
                dp[i][j] = up+left;
            }
        }
    }
    cout<<dp[m-1][n-1];
 }