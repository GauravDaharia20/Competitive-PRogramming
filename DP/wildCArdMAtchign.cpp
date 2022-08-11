/*
Problem Statement
Given a text and a wildcard pattern of size N and M respectively, implement a wildcard pattern matching algorithm that finds if the wildcard pattern is matched with the text. The matching should cover the entire text not partial text.
The wildcard pattern can include the characters ‘?’ and ‘*’
 ‘?’ – matches any single character
 ‘*’ – Matches any sequence of characters(sequence can be of length 0 or more)
Input Format:
The first line contains an Integer 'T' which denotes the number of test cases/queries to be run.
Then the test cases follow.

The first line of input for each test case/query contains a string representing the wildcard pattern.

The second line of input for each test case/query contains a string representing the text.
Output Format:
For each test case, print ‘True’ if the text matches the pattern, print ‘False’ otherwise(without quotes).

Output for every test case will be printed in a separate line.
Note:
You do not need to print anything, it has already been taken care of. Just implement the function.
Constraints:
1 <= T <= 100
1 <= N <= 200
1 <= M <= 200

Where 'N' denotes the length of 'TEXT' and 'M' denotes the length of 'PATTERN'.

'TEXT' and 'PATTERN' contain only lowercase letters and patterns may contain special characters ‘*’ and ‘?’

Time Limit: 1sec
Sample Input 1:
3
?ay
ray
ab*cd
abdefcd
ab?d
abcc
Sample Output 1:
True
True
False
Explanation Of The Sample Input1:
Test Case 1:
The pattern is “?ay” and the text is ray.
‘?’ can match a character so it matches with a character ‘r’ of the text and rest of the text matches with the pattern so we print True.

Test Case 2:
“ab” of text matches with “ab” of pattern and then ‘*’ of pattern matches with “def” of the text and “cd” of text matches with “cd” of the pattern. Whole text matches with the pattern so we print True.

Test Case 3:
“ab” of pattern matches with “ab” of text. ‘?’ of pattern matches with ‘c’ of the text but ‘d’ of the pattern do not match with ‘c’ of the text so we print False.
Sample Input 1:
1
ba*a?
baaabab
Sample Output 1:
True
*/
#include <bits/stdc++.h>
using namespace std;
int help(string pattern, string text, int i, int j, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
        return true;
    if (i == 0 && j > 0)
        return false;
    if (i > 0 && j == 0)
    {

        for (int ii = 1; ii <= i; ii++)
        {
            if (pattern[ii - 1] != '*')
            {
                return false;
            }
        }
        return true;
    }
    if (dp[i][j] != false)
        return dp[i][j];
    if (pattern[i - 1] == text[j - 1] || pattern[i - 1] == '?')
    {
        return dp[i][j] = help(pattern, text, i - 1, j - 1, dp);
    }
    if (pattern[i - 1] == '*')
    {
        return dp[i][j] = (help(pattern, text, i - 1, j, dp) | help(pattern, text, i, j - 1, dp));
    }
    return dp[i][j] = false;
}
bool wildcardMatching(string pattern, string text)
{
    // Write your code here.
    int n = pattern.size();
    int m = text.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
    dp[0][0] = true;
    for (int j = 1; j <= m; j++)
    {
        dp[0][j] = false;
    }
    for (int i = 1; i <= n; i++)
    {
        int flg = true;
        for (int ii = 1; ii <= i; ii++)
        {
            if (pattern[ii - 1] != '*')
            {
                flg = false;
                break;
            }
        }
        dp[i][0] = flg;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (pattern[i - 1] == text[j - 1] || pattern[i - 1] == '?')
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if (pattern[i - 1] == '*')
            {
                dp[i][j] = dp[i - 1][j] | dp[i][j - 1];
            }
            else dp[i][j] = false;
        }
    }
    return dp[n][m];
}

int main()
{
    string pattern = "ab?d";
    string text = "abcc";
    wildcardMatching(pattern, text) == 1 ? cout << "true" : cout << "false";
}