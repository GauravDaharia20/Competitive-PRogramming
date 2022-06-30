/*
You are given an array/list ‘ARR’ of ‘N’ positive integers and an integer ‘K’. Your task is to check if there exists a subset in ‘ARR’ with a sum equal to ‘K’.
Note: Return true if there exists a subset with sum equal to ‘K’. Otherwise, return false.
For Example :
If ‘ARR’ is {1,2,3,4} and ‘K’ = 4, then there exists 2 subsets with sum = 4. These are {1,3} and {4}. Hence, return true.
Input Format :
The first line contains a single integer T representing the number of test cases.

The first line of each test case contains two space-separated integers ‘N’ and ‘K’ representing the size of the input ‘ARR’ and the required sum as discussed above.

The next line of each test case contains ‘N’ single space-separated integers that represent the elements of the ‘ARR’.
Output Format :
For each test case, return true or false as discussed above.
Output for each test case will be printed in a separate line.
Note:
You don’t need to print anything, it has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 5
1 <= N <= 10^3
0 <= ARR[i] <= 10^9
0 <= K <= 10^9

Time Limit: 1 sec
Sample Input 1:
2
4 5
4 3 2 1
5 4
2 5 1 6 7
Sample Output 1:
true
false
Explanation For Sample Input 1:
In example 1, ‘ARR’ is {4,3,2,1} and ‘K’ = 5. There exist 2 subsets with sum = 5. These are {4,1} and {3,2}. Hence, return true.
In example 2, ‘ARR’ is {2,5,1,6,7} and ‘K’ = 4. There are no subsets with sum = 4. Hence, return false.
Sample Input 2:
2
4 4
6 1 2 1
5 6
1 7 2 9 10
Sample Output 2:
true
false
Explanation For Sample Input 2:
In example 1, ‘ARR’ is {6,1,2,1} and ‘K’ = 4. There exist 1 subset with sum = 4. That is {1,2,1}. Hence, return true.
In example 2, ‘ARR’ is {1,7,2,9,10} and ‘K’ = 6. There are no subsets with sum = 6. Hence, return false.
*/
#include<bits/stdc++.h>
using namespace std;
bool help(vector<int>&v,int k,int i,vector<vector<int>>&dp){
    if(k == 0) return true;

    if(i == 0) return v[0] == k;

    if(dp[i][k]!=-1) return dp[i][k];
    bool not_take = help(v,k,i-1,dp);
    bool take = false;
    if(k >= v[i]){
        take = help(v,k-v[i],i-1,dp);
    } 
    return dp[i][k] = (take || not_take);
}
int main()
{
    int k = 4;
    vector<int>v = {6 ,1 ,2 ,1};
    int n = v.size();  
    vector<vector<int>>dp(n,vector<int>(k+1,-1));
    help(v,k,n-1,dp) == 1 ? cout<<"true" : cout<<"false";

    int dp1[n][k+1];
    for(int i=0;i<n;i++){
        dp1[i][0] = 1;
    }
    if(v[0]==k) dp1[0][v[0]] = 1;

    for(int i=1;i<n;i++){
        for(int j=0;j<=k;j++){
            bool not_take = dp1[i-1][j];
            bool take = false;

            if(j >= v[i]){
                take = dp1[i-1][j-v[i]];
            }
            dp1[i][j] = take | not_take;
        }
    }
    cout<<dp1[n-1][k];





}