/*
Problem Statement
You are given an array containing N non-negative integers. Your task is to partition this array into two subsets such that the absolute difference between subset sums is minimum.
You just need to find the minimum absolute difference considering any valid division of the array elements.
Note:
1. Each element of the array should belong to exactly one of the subset.

2. Subsets need not be contiguous always. For example, for the array : {1,2,3}, some of the possible divisions are a) {1,2} and {3}  b) {1,3} and {2}.

3. Subset-sum is the sum of all the elements in that subset.
Input Format:
The first line of input contains the integer T, denoting the number of test cases.

The first line of each test case contains an integer N, denoting the size of the array.

The second and the last line of each test case contains N space-separated integers denoting the array elements.
Output Format:
For each test case, return the minimum possible absolute difference in a separate line.
Note:
You do not need to print anything, it has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 10
1 <= N <= 10^3
0 <= ARR[i] <= 10^3
0 <= SUM <= 10^4,

where SUM denotes the sum of all elements in the array for a given test case.

Time Limit: 1sec
Sample Input 1:
1
4
1 2 3 4
Sample Output 1:
0
Explanation For Sample Input 1:
We can partition the given array into {2,3} and {1,4}, as this will give us the minimum possible absolute difference i.e (5-5=0) in this case.
Sample Input 2:
1
3
8 6 5
Sample Output 2:
3
Explanation For Sample Input 2:
We can partition the given array into {8} and {6,5}, as this will give us the minimum possible absolute difference i.e (11-8=3) in this case
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{

    /*approach:

        use subset sum dp approach and then use the last row values
    */
    int n = 4;
    vector<int> v(n);
    v = {1, 2, 3, 4};
    int sum = accumulate(v.begin(), v.end(), 0);
    bool dp[n][sum + 1];
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }
    if (v[0] <= sum)
        dp[0][v[0]] = true;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            bool not_take = dp[i - 1][j];
            bool take = false;

            if (v[i] <= sum)
            {
                take = dp[i - 1][j - v[i]];
            }
            dp[i][j] = take | not_take;
        }
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<=sum;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    int mini = 1e9;
    for (int s1 = 0; s1 <= sum; s1++)
    {
        if (dp[n - 1][s1] == true)
            mini = min(mini, abs((sum - s1) - s1));
    }
    cout<<mini;
}