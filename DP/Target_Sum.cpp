/*
Problem Statement
You are given an array ‘ARR’ of ‘N’ integers and a target number, ‘TARGET’. Your task is to build an expression out of an array by adding one of the symbols '+' and '-' before each integer in an array, and then by concatenating all the integers, you want to achieve a target. You have to return the number of ways the target can be achieved.
For Example :
You are given the array ‘ARR’ = [1, 1, 1, 1, 1], ‘TARGET’ = 3. The number of ways this target can be achieved is:
1. -1 + 1 + 1 + 1 + 1 = 3
2. +1 - 1 + 1 + 1 + 1 = 3
3. +1 + 1 - 1 + 1 + 1 = 3
4. +1 + 1 + 1 - 1 + 1 = 3
5. +1 + 1 + 1 + 1 - 1 = 3
These are the 5 ways to make. Hence the answer is 5.
Input Format :
The first line of input contains a single integer ‘T’ representing the number of test cases.

The first line of each test case contains two space-separated integers ‘N’ and ‘TARGET’ representing the size of the given array and the target.

The second line of each test case contains ‘N’ space-separated integers representing the elements of the array.
Output Format :
For each test case, print a single integer representing the number of ways to form a target.

Print a separate line for each test case.
Constraints :
1 <= T <= 10
1 <= N <= 35
-1000 <= TARGET <= 1000
0 <= ARR[i] <= 1000

Time Limit: 1 sec
Note :
You do not need to print anything. It has already been taken care of. Just implement the given function.
Sample Input 1 :
2
5 3
1 1 1 1 1
4 3
1 2 3 1
Sample Output 2 :
5
2
Explanation For Sample Input 1 :
For the first test case, ‘ARR’ = [1, 1, 1, 1, 1], ‘TARGET’ = 3. The number of ways this target can be achieved is:
1. -1 + 1 + 1 + 1 + 1 = 3
2. +1 - 1 + 1 + 1 + 1 = 3
3. +1 + 1 - 1 + 1 + 1 = 3
4. +1 + 1 + 1 - 1 + 1 = 3
5. +1 + 1 + 1 + 1 - 1 = 3
These are the 5 ways to get the target. Hence the answer is 5.

For the second test case, ‘ARR’ = [1, 2, 3, 1]. ‘TARGET’ = 3, The number of ways this target can be achieved is:
1. +1 - 2 + 1 + 3 = 3
2. -1 + 2 - 1 + 3 = 3
These are the 3 ways to get the target. Hence the answer is 2.
Sample Input 2 :
2
3 2
1 2 3
2 0
1 1
Sample Output 2 :
1
2

*/
#include <bits/stdc++.h>
using namespace std;
int help(int id, int sum, vector<int> &arr, vector<vector<int>> dp)
{

    if (id == 0)
    {
        if (arr[0] == 0 && sum == 0)
            return 2;
        if (sum == 0 || arr[0] == sum)
            return 1;
        return 0;
    }
    if (dp[id][sum] != -1)
        return dp[id][sum];
    int ntake = help(id - 1, sum, arr, dp);
    int take = 0;
    if (arr[id] <= sum)
    {
        take = help(id - 1, sum - arr[id], arr, dp);
    }
    return dp[id][sum] = (take + ntake);
}
int targetSum(int n, int target, vector<int> &arr)
{
    // Write your code here.
    int sum = accumulate(arr.begin(), arr.end(), 0);
    if ((sum - target < 0) || (sum - target) % 2 != 0)
    {
        return 0;
    }
    int k = (sum - target) / 2;
    vector<vector<int>> dp(arr.size(), vector<int>(k + 1, 0));
    // return help(n-1,k,arr,dp);
    if (arr[0] == 0)
        dp[0][0] = 2;
    else
        dp[0][0] = 1;

    if (arr[0] != 0 && arr[0] <= target)
    {
        dp[0][arr[0]] = 1;
    }

    for (int id = 1; id < arr.size(); id++)
    {
        for (int sum = 0; sum <= target; sum++)
        {
            int ntake = dp[id - 1][sum];
            int take = 0;
            if (arr[id] <= sum)
            {
                take = dp[id - 1][sum - arr[id]];
            }
            dp[id][sum] = (take + ntake);
        }
    }
    return dp[arr.size()-1][target];
}

int main()
{
    int n = 5;
    int target = 3;
    vector<int> v = {1, 1, 1, 1, 1};
    cout << targetSum(n, target, v);
}