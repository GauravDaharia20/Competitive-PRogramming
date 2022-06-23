#include <bits/stdc++.h>
using namespace std;
int minSumPath(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    // Write your code here.

    if (i < 0 || j < 0)
    {
        return INT_MAX;
    }
    if (dp[i][j] != -1)
        return dp[i][j];
    if (i == 0 && j == 0)
    {
        return grid[i][j];
    }
    int up = minSumPath(i - 1, j, grid, dp);
    int left = minSumPath(i, j - 1, grid, dp);
    int ans = grid[i][j] + min(up, left);
    return dp[i][j] = ans;
}
int main()
{
    int n, m;
    n = 2;
    m = 3;
    vector<vector<int>> grid(n, vector<int>(m));
    vector<vector<int>> dp(n, vector<int>(m, -1));
    grid = {
        {5, 9, 6},
        {11, 5, 2}};

    cout << minSumPath(n - 1, m - 1, grid, dp) << endl;

    int mem[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
            {
                mem[i][j] = grid[i][j];
            }
            else
            {
                int up = grid[i][j];
                int left = grid[i][j];
                if (i > 0)
                    up += mem[i-1][j];
                else
                    up += 1e9;
                if (j > 0)
                    left += mem[i][j-1];
                else
                    left += 1e9;
                
                mem[i][j] = min(up,left);
            }
        }
    }
    cout << mem[n - 1][m - 1];
}