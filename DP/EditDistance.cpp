/*
Problem Statement
You are given two strings 'S' and 'T' of lengths 'N' and 'M' respectively. Find the "Edit Distance" between the strings.
Edit Distance of two strings is the minimum number of steps required to make one string equal to the other.
In order to do so, you can perform the following three operations:
1. Delete a character
2. Replace a character with another one
3. Insert a character
Note:
Strings don't contain spaces in between.
 Input Format:
The first line of input contains the string 'S' of length 'N'.

The second line of the input contains the String 'T' of length 'M'.
Output Format:
The only line of output prints the minimum "Edit Distance" between the strings.
Note:
You do not need to print anything; it has already been taken care of. Just implement the given functions.
Constraints:
0 <= N <= 10 ^ 3
0 <= M <= 10 ^ 3

Time Limit : 1sec
Sample Input 1 :
abc
dc
Sample Output 1 :
2
 Explanation For Sample Input 1 :
In 2 operations we can make the string T to look like string S. First, insert the character 'a' to string T, which makes it "adc".

And secondly, replace the character 'd' of the string T with 'b' from the string S. This would make string T to "abc" which is also the string S. Hence, the minimum distance.
Sample Input 2 :
whgtdwhgtdg
aswcfg
Sample Output 2 :
9
*/
#include <bits/stdc++.h>
using namespace std;
int help(string s1, string s2, int i, int j, vector<vector<int>> &dp)
{
    if (i < 0)
        return j + 1;
    if (j < 0)
        return i + 1;
    // int insert,delete,replace;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s1[i] == s2[j])
    {
        return dp[i][j] = 0 + help(s1, s2, i - 1, j - 1, dp);
    }

    int ins = help(s1, s2, i, j - 1, dp);
    int del = help(s1, s2, i - 1, j, dp);
    int rep = help(s1, s2, i - 1, j - 1, dp);

    return dp[i][j] = 1 + min(ins, min(del, rep));
}
int editDistance(string str1, string str2)
{
    // write you code here
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    // return help(str1, str2, n - 1, m - 1,dp);
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = i;
    }

    for (int i = 0; i <= m; i++)
    {
        dp[0][i] = i;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] =  dp[i - 1][j - 1];
            }
            else
            {
                int inst = dp[i][j - 1];
                int delt = dp[i - 1][j];
                int reps = dp[i - 1][j - 1];

                dp[i][j] = 1 + min(inst, min(delt, reps));
            }
        }
    }
    return dp[n][m];
}
int main()
{
    string s1, s2;
    s1 = "abc";
    s2 = "dc";
    cout << editDistance(s1, s2);
}