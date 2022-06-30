/*
Problem Statement
You have been given an N*M matrix filled with integer numbers,
find the maximum sum that can be obtained from a path starting from any cell in the first row to any cell in the last row.
From a cell in a row, you can move to another cell directly below that row, or diagonally below left or right. So from a particular cell (row, col), we can move in three directions i.e.
Down: (row+1,col)
Down left diagonal: (row+1,col-1)
Down right diagonal: (row+1, col+1)
*/
#include <bits/stdc++.h>
using namespace std;

int getMaxPathSum(vector<vector<int>> &grid,int i,int j,vector<vector<int>> &dp)
{
    //  Write your code here.
    if(j >=grid[0].size() || j < 0){
        return -1e8;
    }
    if(i==0){
        return grid[i][j];
    }
    if(dp[i][j]!=-1) return dp[i][j];

    int up = grid[i][j]+ getMaxPathSum(grid,i-1,j,dp);
    int ld = grid[i][j]+ getMaxPathSum(grid,i-1,j-1,dp);
    int rd = grid[i][j]+ getMaxPathSum(grid,i-1,j+1,dp);
    return dp[i][j] = max({up,ld,rd});

}
int main()
{
    int n = 3;
    int m = 3;
    vector<vector<int>> grid(n, vector<int>(m));
    vector<vector<int>> dp(n, vector<int>(m,-1));
    grid = {
        {10, 2, 3}, {3, 7, 2}, {8, 1, 5}
        };
    int ans = -1e8;
    for(int j=0;j<m;j++)
    {
        int temp = getMaxPathSum(grid,n-1,j,dp);
        ans = max(ans,temp);
    }
    cout<<ans;
}