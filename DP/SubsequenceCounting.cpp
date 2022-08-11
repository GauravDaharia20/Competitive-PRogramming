/*
Subsequence Counting
Difficulty: MEDIUM
Contributed By
TanishkTonk
|
Level 1
Problem Statement
Statement:

We are given two strings, ‘TEXT' and ‘S’. We have to calculate the no. of subsequences of ‘TEXT’, which are equal to ‘S’. Since the answer can be very large print it modulo (10^9)+7.
A Subsequence of a string is the string that is generated by deleting 0 or more letters from the string and keeping the rest of the letters in the same order.
For Example:
‘TEXT’ = “brootgroot” and ‘S’ = “brt”
Following subsequences formed by characters at given indices (1-based) of TEXT are counted
1 2 5
1 2 10
1 7 10
So, our output will be:
3
Input Format:
The first line of input contains a single integer ‘T’ representing the number of test cases.

The first line of each test case contains two space-separated integers ‘M’ and ‘N’, denoting lengths of ‘TEXT’ and ‘S’, respectively.

The second line of each test case will contain a string ‘TEXT’, denoting the first string of the problem statement.

The third line of each test case will contain a string ‘S’, denoting the second string of the problem statement.
Output Format:
For each test case, print a single integer value, denoting no. of subsequences of ‘TEXT’ which are equal to ‘S’ modulo (1000000007).

Print a separate line for each test case.
Note:
You are not required to print anything; it has already been taken care of. Just implement the function and return the answer.
Constraints -
1 ≤ T ≤ 1000
1 ≤ M,N ≤ 1000
The sum of lengths of all the strings in all test cases doesn’t exceed 3000.
Sample Input 1 :
2
13 2
codingniinjas
in
10 3
brootgroot
brt
Sample Output 1 :
5
3
Explanation For Sample Input 1 :
For the first test case, the following subsequences formed by characters at given indices (1-based) of TEXT are counted
4 5
4 7
4 10
8 10
9 10

The second test case will be similar as described above in the example.
Sample Input 2 :
2
16 3
dingdingdingding
ing
4 2
abac
cb
Sample Output 2 :
20
0
*/
#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
int help(string a, string b, int i, int j, vector<vector<int>> &dp)
{

    if (j == 0)
        return 1;
    if (i == 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (a[i] == b[j])
    {
        return dp[i][j] = help(a, b, i - 1, j - 1, dp) + help(a, b, i - 1, j, dp);
    }
    return dp[i][j] = help(a, b, i - 1, j, dp);
}
int countOccurence(string a, string b)
{
    int n = a.size();
    int m = b.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0){
                dp[i][j] = 0;
            }
            else if(j==0){
                dp[i][j] = 1;
            }
            else if(a[i-1]==b[j-1]){
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%mod;
            }
            else{
                dp[i][j] = (dp[i-1][j])%mod;
            }
        }
    }
    
    return dp[n][m]%mod;
}
int main()
{
    string a = "codingniinjas";
    string b = "in";
    cout << countOccurence(a, b);
}