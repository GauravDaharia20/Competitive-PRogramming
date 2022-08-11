/*
You are given an infinite supply of coins of each of denominations D = {D0, D1, D2, D3, ...... Dn-1}. 
You need to figure out the total number of ways W, in which you can make a change for value V using coins of denominations from D. 
Print 0, if a change isn't possible.
Input Format
The first line of input contains an integer N, representing the total number of denominations.

The second line of input contains N integers values separated by a single space. Each integer value represents the denomination value.

The third line of input contains the value of V, representing the value for which the change needs to be generated.
Output Format:
For each test case, print an integer denoting the total number of ways W, in which a change for V is possible.
Note:
You do not need to print anything, it has already been taken care of. Just implement the given function.
Constraints :
1 <= N <= 10
1 <= D[i] <=10^5
1 <= V <= 2 * 10^3

Where 'D[i]' represent the value of ith denomination.

Time Limit: 1sec
Sample Input 1 :
3
1 2 3
4
Sample Output 1:
4
Explanation For Sample Output 1:
We can make a change for the value V = 4 in four ways.
1. (1,1,1,1),
2. (1,1, 2), [One thing to note here is, (1, 1, 2) is same as that of (2, 1, 1) and (1, 2, 1)]
3. (1, 3), and
4. (2, 2)
Sample Input 2 :
3
5 3 2
1
Sample Output 2:
0
*/
#include <bits/stdc++.h>
using namespace std;
long countWaysToMakeChange(vector<int> &v, int id, int value,vector<vector<int>>&dp)
{
    // Write your code here
    if (id == 0)
    {
        // either value == v[id] or it is divisible
        return (value % v[id]) == 0;
    }
    if(dp[id][value]!=-1){
        return dp[id][value];
    }
    int not_take = countWaysToMakeChange(v, id - 1, value,dp);
    int take = 0;
    if (v[id] <= value)
    {
        take = countWaysToMakeChange(v, id, value - v[id],dp);
    }
    return dp[id][value] =  (take + not_take);
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int target;
    cin >> target;
    vector<vector<int>>dp(n,vector<int>(target,0));
    //cout << countWaysToMakeChange(v, n - 1, t,dp);
    for(int t=0;t<=target;t++){
        dp[0][t] = (t%v[0]==0);
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<=target;j++){
            int not_take = dp[i-1][j];
            int take = 0;
            if(v[i]<=j){
                take = dp[i][j-v[i]];
            }
            dp[i][j] = take+not_take;
        }
    }
    cout<<dp[n-1][target];
}