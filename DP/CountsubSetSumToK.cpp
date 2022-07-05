/*
Problem Statement
You are given an array (0-based indexing) of positive integers and you have to tell how many different ways of selecting the elements from the array are there such that the sum of chosen elements is equal to the target number “tar”.
Note:
Two ways are considered different if sets of indexes of elements chosen by these ways are different.

Input is given such that the answer will fit in a 32-bit integer.
For Example:
If N = 4 and tar = 3 and the array elements are [1, 2, 2, 3], then the number of possible ways are:
{1, 2}
{3}
{1, 2}
Hence the output will be 3.
Input Format :
The first line of the input contains an integer, 'T’, denoting the number of test cases.

The first line of each test case will contain two space-separated integers ‘N’ and “tar”, denoting the size of the array and the target sum.

The second line of each test case contains ‘N’ space-separated integers denoting elements of the array.
Output Format :
For each test case, print the number of ways that satisfy the condition mentioned in the problem statement.

Print a separate line for each test case.
*/
#include <bits/stdc++.h>
using namespace std;
int findWays(vector<int> &v, int sum, int id, vector<vector<int>> dp)
{

    if (id == 0)
    {
        if (sum == 0 && v[0] == 0)
            return 2;
        if (sum == 0 || sum == v[0])
            return 1;
        return 0;
    }
    if (dp[id][sum] != -1)
        return dp[id][sum];
    int not_pick = findWays(v, sum, id - 1, dp);
    int pick = 0;
    if (v[id] <= sum)
    {
        pick = findWays(v, sum - v[id], id - 1, dp);
    }
    return dp[id][sum] = (pick + not_pick);
}
int main()
{

    vector<int> v = {1, 2, 2, 3};
    int t = 3;
    vector<vector<int>> dp(v.size(), vector<int>(t + 1));
    cout << findWays(v, t, v.size() - 1, dp);
    // for(int i=0;i<v.size();i++){
    //     dp[i][0] = 1;
    // }
    // if(v[0] <=t) dp[0][v[0]] = 1;
    // for(int i=1;i<v.size();i++){
    //     for(int j= 0 ; j<=t;j++){
    //         int ntake = dp[i-1][j];
    //         int pick = 0;
    //         if(v[i] <=j){
    //             pick = dp[i-1][j-v[i]];
    //         }
    //         dp[i][j] = pick + ntake;
    //     }
    // }
    // cout<<dp[v.size()-1][t];
}