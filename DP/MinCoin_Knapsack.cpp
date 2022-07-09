/*
Problem Statement
You are given an array of ‘N’ distinct integers and an integer ‘X’ representing the target sum. You have to tell the minimum number of elements you have to take to reach the target sum ‘X’.
Note:
You have an infinite number of elements of each type.
For Example
If N=3 and X=7 and array elements are [1,2,3].
Way 1 - You can take 4 elements  [2, 2, 2, 1] as 2 + 2 + 2 + 1 = 7.
Way 2 - You can take 3 elements  [3, 3, 1] as 3 + 3 + 1 = 7.
Here, you can see in Way 2 we have used 3 coins to reach the target sum of 7.
Hence the output is 3.
Input Format :
The first line of the input contains an integer, 'T’, denoting the number of test cases.

The first line of each test case will contain two space-separated integers ‘N’ and ‘X’, denoting the size of the array and the target sum.

The second line of each test case contains ‘N’ space-separated integers denoting elements of the array.
Output Format :
For each test case, print the minimum number of coins needed to reach the target sum ‘X’, if it's not possible to reach to target then print "-1".

Print a separate line for each test case.
Note :
You do not need to print anything, it has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 10
1 <= N <= 15
1 <= nums[i] <= (2^31) - 1
1 <= X <= 10000

All the elements of the “nums” array will be unique.
Time limit: 1 sec
Sample Input 1 :
2
3 7
1 2 3
1 0
1
Sample Output 1 :
 3
 0
Explanation For Sample Output 1:
For the first test case,
Way 1 - You can take 4 elements  [2, 2, 2, 1] as 2 + 2 + 2 + 1 = 7.
Way 2 - You can take 3 elements  [3, 3, 1] as 3 + 3 + 1 = 7.
Here, you can see in Way 2 we have used 3 coins to reach the target sum of 7.
Hence the output is 3.

For the second test case,
Way 1 - You can take 3 elements  [1, 1, 1] as 1 + 1 + 1  = 3.
Way 2 - You can take 2 elements  [2, 1] as 2 + 1 = 3.
Here, you can see in Way 2 we have used 2 coins to reach the target sum of 7.
Hence the output is 2.
Sample Input 2 :
2
3 4
12 1 3
2 11
2 1
Sample Output 2 :
2
6
*/
#include <bits/stdc++.h>
using namespace std;
int help(vector<int> &num, int x, int id, vector<vector<int>> &dp)
{

    if (id == 0)
    {
        if (x % num[id] == 0)
            return (x / num[id]);
        return (int)(1e9);
    }

    if (dp[id][x] != -1)
        return dp[id][x];
    int ntake = 0 + help(num, x, id - 1, dp);
    int take = INT_MAX;
    if (num[id] <= x)
    {
        take = 1 + help(num, x - num[id], id, dp);
    }
    return dp[id][x] = min(ntake, take);
}
int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(x + 1, -1));
    return help(num, x, num.size() - 1, dp);
}
int main()
{
    int n, x;
    n = 3;
    x = 7;
    vector<int> deno(n);
    deno = {1, 2, 3};
    cout << minimumElements(deno, x)<<endl;
    vector<vector<int>> dp(n, vector<int>(x + 1, 0));
    for (int t = 0; t <= x; t++)
    {
        if (t % deno[0] == 0)
        {
            dp[0][t] = t / deno[0];
        }
        else
        {
            dp[0][t] = 1e9;
        }
    }

    for (int id = 1; id < n; id++)
    {
        for (int t = 0; t <= x; t++)
        {

            int ntake = 0 + dp[id - 1][t];
            int take = INT_MAX;
            if (deno[id] <= t)
            {
                take = 1 + dp[id][t - deno[id]];
            }
            dp[id][t] = min(ntake, take);
        }
    }
    cout<<dp[n-1][x];
}