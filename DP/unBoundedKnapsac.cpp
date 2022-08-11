/*
You are given ‘N’ items with certain ‘PROFIT’ and ‘WEIGHT’ and a knapsack with weight capacity ‘W’. 
You need to fill the knapsack with the items in such a way that you get the maximum profit. 
You are allowed to take one item multiple times.
For Example
Let us say we have 'N' = 3 items and a knapsack of capacity 'W' =  10
'PROFIT' = { 5, 11, 13 }
'WEIGHT' = { 2, 4, 6 }

We can fill the knapsack as:

1 item of weight 6 and 1 item of weight 4.
1 item of weight 6 and 2 items of weight 2.
2 items of weight 4 and 1 item of weight 2.
5 items of weight 2.

The maximum profit will be from case 3 i.e ‘27’. Therefore maximum profit = 27.
Input Format
The first line contains a single integer ‘T’ denoting the number of test cases.

The first line of each test contains two integers ‘N’ - number of elements in the array and ‘W’ - Capacity of the knapsack.

The second line of each test case contains profiti - profit of the item at the ‘i-th’ index.

The third line of each test case contains weighti - weight of the item at the ‘i-th’ index
Output Format
For each test case, return an integer denoting the maximum profit that can be obtained by filling the knapsack.
Note:
You do not need to print anything; it has already been taken care of. Just implement the given function.
Constraints
1 <= T <= 50
1 <= N <= 10^3
1 <= W <= 10^3
1 <= PROFIT[ i ] , WEIGHT[ i ] <= 10^8

Time Limit: 1sec
Sample Input 1
2
3 15
7 2 4
5 10 20
2 3
6 12
4 17
Sample Output 1
21
0
Explanation Of Sample Input 1
Test Case 1:  The given knapsack capacity is 15. We can fill the knapsack as [5, 5, 5] and [10, 5]. We will get a maximum profit of 21.

Test Case 2: We can clearly see that no item has wait less than knapsack capacity. Therefore we can not fill knapsack with any item.
Sample Input 2
2
4 7
3 4 5 1
4 1 2 3
3 9
1 2 3
1 3 5
Sample Output 2
28
9
*/
#include <bits/stdc++.h>
using namespace std;
int help(int id, int w, vector<int> &profit, vector<int> &weight,vector<vector<int>>&dp)
{

    // base
    if (id == 0)
    {
        return ((w / weight[0]) * profit[0]);
    }
    // recur
    if(dp[id][w]!=-1){
        return dp[id][w];
    }
    int not_take = 0 + help(id - 1, w, profit, weight,dp);
    int take = INT_MIN;
    if (weight[id] <= w)
    {
        take = profit[id] + help(id, w - weight[id], profit, weight,dp);
    }
    return dp[id][w] =  max(take, not_take);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    vector<vector<int>>dp(n,vector<int>(w+1,-1));
    return help(n - 1, w, profit, weight,dp);
}

int main()
{
    vector<int> profit = {3, 4, 5, 1};
    vector<int> weight = {4, 1, 2, 3};
    int n = profit.size();
    int w = 7;
    cout << unboundedKnapsack(n, w, profit, weight);
    vector<vector<int>>dp(n,vector<int>(w+1,0));

    for(int wt = 0;wt<=w;wt++){
        dp[0][wt] = ((wt/weight[0])*profit[0]);
    }

    for(int id=1;id<n;id++){
        for(int wt = 0;wt<=w;wt++){
            int not_take = 0 + dp[id-1][wt];
            int take = INT_MIN;
            if(weight[id]<=wt){
                take = profit[id] + dp[id][wt-weight[id]];
            }
            dp[id][wt] = max(take,not_take);
        }
    }
    cout<<dp[n-1][w];
}