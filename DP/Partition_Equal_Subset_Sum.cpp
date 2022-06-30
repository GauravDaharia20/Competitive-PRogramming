/*
Problem Statement
You are given an array 'ARR' of 'N' positive integers. Your task is to find if we can partition the given array into two subsets such that the sum of elements in both subsets is equal.
For example, let’s say the given array is [2, 3, 3, 3, 4, 5], then the array can be partitioned as [2, 3, 5], and [3, 3, 4] with equal sum 10.
Follow Up:
Can you solve this using not more than O(S) extra space, where S is the sum of all elements of the given array?
Input Format:
The first line of input contains an integer 'T' representing the number of test cases or queries to be processed.
Then the test case follows.

The first line of each test case contains an integer 'N', denoting the size of the array.

The second line of each test case contains 'N' single space-separated integers representing the array elements.
Output Format:
For each test case, print “true” or “false” denoting whether we can partition into two equal subset-sum or not, in a separate line. 
Note:
You do not need to print anything; it has already been taken care of. Just implement the given function.
Constraints:
1 <= 'T' <= 10
1 <= 'N' <= 100 
1 <= 'ARR'[i] <= 100

Time Limit: 1 sec
Sample Input 1:
2
6
3 1 1 2 2 1
5
5 6 5 11 6
Sample Output 1:
true
false    
Explanation Of Sample Input 1:
For the first test case, the array can be partitioned as ([2,1,1,1] and [3, 2]) or ([2,2,1], and [1,1,3]) with sum 5.

For the second test case, the array can’t be partitioned.
Sample Input 2:
2
9
2 2 1 1 1 1 1 3 3
6
8 7 6 12 4 5
Sample Output 2:
false
true

*/
#include<bits/stdc++.h>
using namespace std;
bool help(vector<int>&v,int i,int sum,vector<vector<bool>>&dp){

    if(sum == 0) return 0;

    if(i == 0) return v[0]==sum;

    if(dp[i][sum]!=false) return dp[i][sum];
    bool not_take = help(v,i-1,sum,dp);
    bool take = false;
    if(sum >= v[i]){
        take = help(v,i-1,sum-v[i],dp);
    }
    return dp[i][sum] = (take | not_take);
}
int main()
{
    vector<int>v = {8 ,7 ,6 ,12 ,4 ,5};
    int n = v.size();
    int sum = accumulate(v.begin(),v.end(),0);
    vector<vector<bool>>dp(n,vector<bool>((sum/2)+1,false));
    if(sum&1) cout<<"false";
    for(int i=0;i<n;i++){
        dp[i][0] = true;
    }
    if(v[0] <= (sum/2)) dp[0][v[0]]=true;
    for(int i=1;i<n;i++){
        for(int j=1;j<=(sum/2);j++){
            bool not_take = dp[i-1][j];
            bool take = false;
            
            if(j >= v[i]){
                take = dp[i-1][j-v[i]];
            }
            
            dp[i][j] = (take | not_take);
        }
    }
    return dp[n-1][sum/2];
    
}