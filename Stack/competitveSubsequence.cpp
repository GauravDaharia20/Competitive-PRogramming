/*You are given an array of integers, ‘ARR’, and a positive integer, ‘C’. Your task is to return the most competitive subsequence of ‘ARR’ of size ‘C’.
Given ‘a1’ and ‘a2’ as subsequences (of the same size) of ‘ARR’. Subsequence ‘a1’ is said to be more competitive than subsequence ‘a2’ if, at the first non-matching position in ‘a1’ and ‘a2’, subsequence ‘a1’ has an integer less than the corresponding integer in ‘a2’.
Note:
1) A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

2) Given arr = {1, 3, 4, 5, 6} and C = 3, subsequence {1, 3, 4} is more competitive than {1, 3, 5} because at the first non-matching position, i.e., at index 2, 4 (in first subsequence) < 5 (in second subsequence).
Input Format:
The first line of input contains an integer 'T' representing the number of test cases.

The first line of each test case contains an integer ‘N’ representing the total number of integers in ‘ARR’.

The second line of each test case contains 'N' space-separated integers representing the array elements.

The last line of each test case contains an integer ‘C’ representing the size of the most competitive subsequence.
Output Format:
For each test case, return the most competitive subsequence.

The output of each test case will be printed in a separate line.
Note:
You do not need to print anything, it has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 5
1 <= C <= N <= 10^3
0 <= ARR[ i ] <= 10 ^ 9

Time limit: 1 second
Sample Input 1:
2
4
2 1 4 3 
2
5
7 4 1 3 6
3 
Sample Output 1:
1 3
1 3 6
Explanation of Sample Output 1:
Test Case 1 :  

Given arr = {2, 1, 4, 3} and C = 2. Among all the subsequences of size 2: {2, 1}, {2,  4}, {2, 3}, {1, 4}, {1, 3} and {4, 3}, the subsequence {1, 3} is the most competitive.


Test Case 2 : 

Given arr = {7, 4, 1, 3, 6} and C = 3. Among all the subsequences of size 3: {7, 4, 1}, {7, 4, 3}, {7, 4, 6}, {7, 1, 3}, {7, 1, 6}, {4, 1, 3}, {4, 1, 6}, {4, 3, 6} and {1, 3, 6}, the subsequence {1, 3, 6} is the most competitive.
Sample Input 2:
2
6
3 10 8 13 25 7
3
4
8 8 8 8
2
Sample Output 2:
3 8 7
8 8
*/
#include<bits/stdc++.h>
using namespace std;

// approach : there is n-i element to push and s.size()-1 element in stack then total size is (s.size()-1+n-i)
int main()
{   stack<int>s;
    vector<int>v={2 ,22 ,21 ,25 ,23 ,9 ,16 ,25 ,23 ,2 ,24 ,9 ,15 ,24};
    int k = 5;
    int n = v.size();
    for(int i=0;i<n;i++){
        while(!s.empty() && s.size()-1+n-i >=k && s.top() > v[i]){
            s.pop();
        }
        if(s.size()<k){
            s.push(v[i]);
        }
    }    

    while (!s.empty())
    {
        /* code */
        cout<<s.top()<<" ";
        s.pop();
    }
    
}