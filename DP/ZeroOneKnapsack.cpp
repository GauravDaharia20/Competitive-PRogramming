/*
A thief is robbing a store and can carry a maximal weight of W into his knapsack. There are N items and the ith item weighs wi and is of value vi. Considering the constraints of the maximum weight that a knapsack can carry, you have to find and return the maximum value that a thief can generate by stealing items.
Input Format:
The first line contains a single integer T representing the number of test cases.      
The T-test cases are as follows:

Line 1:The first line contains an integer, that denotes the value of N. 
Line 2:The following line contains N space-separated integers, that denote the values of the weight of items. 
Line 3:The following line contains N space-separated integers, that denote the values associated with the items. 
Line 4:The following line contains an integer that denotes the value of W. W denotes the maximum weight that a thief can carry.
Output Format :
The first and only line of output contains the maximum value that a thief can generate, as described in the task. 
The output of every test case is printed in a separate line.
Constraints:
1 <= T <= 10
1 <= N <= 10^2
1<= wi <= 50
1 <= vi <= 10^2
1 <= W <= 10^3

Time Limit: 1 second
Follow Up:
Can we solve this using space complexity of not more than O(W)?
Sample Input:
1 
4
1 2 4 5
5 4 8 6
5
Sample Output:
13

*/
#include<bits/stdc++.h>
using namespace std;
int help(vector<int> &weight, vector<int> &value, int id, int W){

    if(id == 0){
        if(weight[0]<=W) return value[0];
        return 0;
    }
    int ntake = 0 + help(weight,value,id-1,W);
    int take = INT_MIN;
    if(weight[id]<=W){
        take = value[id] + help(weight,value,id-1,W-weight[id]);
    }
    return max(ntake,take);
}
int knapsack(vector<int> weight, vector<int> value, int n, int W) 
{
	return help(weight,value,n-1,W);
}
int main()
{
   vector<int> weight = {1 ,2 ,4 ,5};
   vector<int>value = {5 ,4 ,8, 6};
   int W = 5;
   int n = value.size();
    cout<<knapsack(weight,value, n, W)<<endl ;
    vector<vector<int>>dp(n,vector<int>(W+1,0));
    for(int i=weight[0];i<=W;i++){
        dp[0][i] = value[0];
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<=W;j++){
            int ntake = 0+dp[i-1][j];
            int take = INT_MIN;
            if(weight[i]<=j){
                take = value[i]+dp[i-1][j-weight[i]];
            }
            dp[i][j] = max(take,ntake);
        }
    }
    cout<<dp[n-1][W];
}