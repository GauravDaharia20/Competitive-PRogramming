/*
You are given a triangular array/list 'TRIANGLE'. Your task is to return the minimum path sum to reach from the top to the bottom row.
The triangle array will have N rows and the i-th row, where 0 <= i < N will have i + 1 elements.
You can move only to the adjacent number of row below each step. For example, if you are at index j in row i, then you can move to i or i + 1 index in row j + 1 in each step.
For Example :
If the array given is 'TRIANGLE' = [[1], [2,3], [3,6,7], [8,9,6,1]] the triangle array will look like:

1
2,3
3,6,7
8,9,6,10

For the given triangle array the minimum sum path would be 1->2->3->8. Hence the answer would be 14.
Input Format :
The first line of input contains an integer ‘T’ denoting the number of test cases to run. Then the test case follows.

The first line of each test case contains an integer ‘N’  representing the length of the array/list triangle.

Then N lines follow. Each of the ith row contains i + 1 space-separated integers denoting the elements of the array/list 'TRIANGLE'.
*/
#include <bits/stdc++.h>
using namespace std;
int minimumPathSum(vector<vector<int>> grid, int n, int i, int j, vector<vector<int>> &dp)
{

    if (i == n - 1)
    {
        return grid[n - 1][j];
    }

    if (dp[i][j] != -1)
        return dp[i][j];

    int down = minimumPathSum(grid, n, i + 1, j, dp) + grid[i][j];
    int dg = minimumPathSum(grid, n, i + 1, j + 1, dp) + grid[i][j];
    return dp[i][j] = min(down, dg);
}
int main()
{
    vector<vector<int>> grid = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}};
    //vector<vector<int>> dp(4, vector<int>(4, -1));
    //cout << minimumPathSum(grid, 4, 0, 0, dp);

    int dps[4][4];
    for(int i=0;i<4;i++){
        dps[3][i] = grid[3][i];
    }

    for(int i=2;i>=0;i--){
        for(int j=i;j >=0;j--){
            int down = grid[i][j] + dps[i+1][j];
            int dg = grid[i][j] + dps[i+1][j+1];
            dps[i][j] = min(down,dg);
        }
    }   
    cout<<dps[0][0];

}