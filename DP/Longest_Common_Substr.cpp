/*
Problem Statement
You have been given two strings 'STR1' and 'STR2'. You have to find the length of the longest common substring.
A string “s1” is a substring of another string “s2” if “s2” contains the same characters as in “s1”, in the same order and in continuous fashion also.
For Example :
If 'STR1' = “abcjklp” and 'STR2' = “acjkp”  then the output will be 3.

Explanation: The longest common substring is “cjk” which is of length 3.
Input Format:
The first line contains an integer ‘T’ which denotes the number of test cases.

The first and only line of each test case contains two space-separated strings 'STR1' and 'STR2', respectively.
Output Format:
For each test case, return the length of the longest common substring among the two strings.

Print the output of each test case in a separate line.
Note:
You don't need to print anything, it has been already taken care of. Just implement the given function.
Constraints:
1 <= T <= 100
1 <= |STR1|, |STR2| <= 100

Where |STR1| and |STR2|  are the lengths of the string 'STR1' and 'STR2' respectively.

Time limit: 1 sec
Sample Input 1:
2
abcjklp acjkp
wasdijkl wsdjkl
Sample Output 1:
3
3
Explanation For Sample Output 1:
In test case 1, the longest common substring is "cjk" of length 3.

In test case 2, the longest common substring is "jkl" of length 3.
Sample Input 2:
2
abcy acby
tyfg cvbnuty
Sample Output 2:
1
2
Explanation For Sample Output 2:
In test case 1, the longest common substring is "a" of length 1. Other substrings of length 1 are also possible as answers.

In test case 2, the longest common substring is "ty" of length 2.
*/
#include <bits/stdc++.h>
using namespace std;
int lcs(string &s, string &t){
	//	Write your code here.
    int n = s.size();
    int m = t.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }else if(s[i-1]==t[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
    return dp[n][m];
}
int main()
{
    string s = "abcy"; 
    string t = "acby";
    cout<<lcs(s,t);
}