/*
Problem Statement
Given two strings, 'S' and 'T' with lengths 'M' and 'N', find the length of the 'Longest Common Subsequence'.
For a string 'str'(per se) of length K, the subsequences are the strings containing characters in the same relative order as they are present in 'str,' but not necessarily contiguous. Subsequences contain all the strings of length varying from 0 to K.
Example :
Subsequences of string "abc" are:  ""(empty string), a, b, c, ab, bc, ac, abc.
Input Format :
The first line of input contains the string 'S' of length 'M'.

The second line of the input contains the string 'T' of length 'N'.
Output Format :
Return the length of the Longest Common Subsequence.
Constraints :
0 <= M <= 10 ^ 3
0 <= N <= 10 ^ 3

Time Limit: 1 sec
Sample Input 1 :
adebc
dcadb
Sample Output 1 :
3
Explanation Of The Sample Output 1 :
Both the strings contain a common subsequence 'adb', which is the longest common subsequence with length 3.
Sample Input 2 :
ab
defg
Sample Output 2 :
0
Explanation Of The Sample Output 2 :
The only subsequence that is common to both the given strings is an empty string("") of length 0.
*/
#include <bits/stdc++.h>
using namespace std;
int help(string s, string t, int id1, int id2, vector<vector<int>> dp)
{
    if (id1 == 0 || id2 == 0)
    {
        return 0;
    }
    if (dp[id1][id2] != -1)
    {
        return dp[id1][id2];
    }
    if (s[id1 - 1] == t[id2 - 1])
    {
        return dp[id1][id2] = 1 + help(s, t, id1 - 1, id2 - 1, dp);
    }
    return dp[id1][id2] = max(help(s, t, id1 - 1, id2, dp), help(s, t, id1, id2 - 1, dp));
}
int lcs(string s, string t)
{
    // Write your code here
    vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, -1));
    return help(s, t, s.size(), t.size(), dp);
}
int main()
{
    string s = "adebc";
    string t = "dcadb";
    cout << lcs(s, t);
    vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));

    for (int id1 = 0; id1 <= s.size(); id1++)
    {
        for (int id2 = 0; id2 <= t.size(); id2++)
        {
            if (id1 == 0 || id2 == 0)
            {
                dp[id1][id2] = 0;
            }
            else if (s[id1-1] == t[id2-1])
            {
                dp[id1][id2] = 1 + dp[id1 - 1][id2 - 1];
            }
            else
            {
                dp[id1][id2] = max(dp[id1 - 1][id2], dp[id1][id2 - 1]);
            }
        }
    }
    //cout << dp[s.size()][t.size()];
    int i = s.size(); int j = t.size();
    while(i>0 && j>0){
        if(s[i-1]==t[j-1]){
            cout<<s[i-1]<<" ";
            i--;j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]){
            i=i-1;
        }
        else{
            j=j-1;
        }
    }
}