/*
Problem Statement
A palindrome string is one that reads the same backward as well as forward. Given a string 'STR', you need to tell the minimum number of characters needed to insert into it to make it a palindromic string.
For example:
String 'STR' = “abcaa” can be converted into a palindrome by inserting 2 characters. So the final string becomes “aabcbaa”.
Input Format:
The first line of input contains an integer 'T' denoting the number of test cases or queries.

The first and only line of each test case contains a string 'STR', containing lowercase English letters i.e from 'a’ to ‘z’.
Output Format:
For each test case, print a single line containing a single integer denoting the minimum number of insertions needed to make 'STR' palindrome.

The output of each test case will be printed in a separate line.
Note:
You do not need to print anything, it has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 100   
1 <= |STR| <= 10 ^ 2

Where |STR| represents the length of the string 'STR'.

Time Limit: 1 sec.
Sample Input 1:
2
abcaa
edge
Sample Output 1:
2
1
Explanation For Input 1:
For test case 1: Refer to example explain above.

For test case 2: you can make “egdge” or “edgde” in one operation.
Sample Input 2:
2
codingninjas
helper
Sample Output 2:
7
3
*/
#include<bits/stdc++.h>
int minInsertion(string &str)
{
    // Write your code here.
    int n = str.size();
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    string s1 = str;
    reverse(str.begin(),str.end());
    string s2 = str;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
            else if(s1[i-1]==s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
    }
    return n-dp[n][n];
}