/*Problem Statement
You are given an array/list ‘ARR’ consisting of ‘N’ distinct integers. You need to check whether ‘ARR’ can represent the Preorder Traversal of a Binary Search Tree.
You should return true if ‘ARR’ can represent Preorder Traversal of a Binary Search Tree, otherwise return false.

Consider ‘ARR’ = [40, 30, 35, 80, 100]. You can see that it is the preorder traversal of the Binary Search Tree shown above.

Thus, we should return true in this case.
Input Format:
The first line of input contains an integer ‘T’ denoting the number of test cases. then ‘T’ test cases follow.

The first line of each test case consists of a single integer ‘N’ representing the size of the list/array ‘ARR’.

The second line of each test case consists of ‘N’ single space-separated integers representing list/ array ‘ARR’.
Output Format :
For each test case, print a single line containing a string ‘True’ if  ‘ARR’ can represent Preorder Traversal of a Binary Search Tree, otherwise print ‘False’.  

The output of each test case will be printed in a separate line.
Note:
You do not need to print anything, it has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 50
1 <= N <= 10 ^ 4
1 <= ARR[i] <= 10 ^ 9

Where ‘ARR[i]’ is the element of the given array ‘ARR’ at index ‘i’.   

Time limit: 1 sec.
Sample Input 1:
2
1
1
5
40 30 35 80 100
Sample Output 1:
True
True
Explanation Of Sample Input 1:
Test case 1:
There is only one element is ‘ARR’, and it is the preorder traversal of a Binary Search tree having a single node with value 1.

Test case 2:
See the problem statement for an explanation.
Sample Input 2:
2
3
2 4 1
6
5 2 3 1 7 8
Sample Output 2:
False
False

*/
#include<bits/stdc++.h>
using namespace std;
bool isBSTPreorder(vector<int>v)
{
    stack<int>s;
    int n = v.size();
    int root=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(v[i] < root) return false;

        while(!s.empty() && s.top() < v[i]){
            root = s.top();
            s.pop();
        }
        s.push(v[i]);
    }
    return true;
}
int main()
{
    vector<int>v={40,30,35,80,100};
    cout<<isBSTPreorder(v);
}
