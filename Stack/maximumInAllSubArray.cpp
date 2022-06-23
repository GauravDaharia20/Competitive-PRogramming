/*Problem Statement
Given an array/list ‘ARR’ of integers and an integer ‘K’. You are supposed to return the maximum for every subarray of the given array of length ‘K’.
Note :
An array ‘B’ is a subarray of an array ‘A’ if ‘B’ that can be obtained by deletion of, several elements(possibly none) from the start of ‘A’ and several elements(possibly none) from the end of ‘A’. 
Input Format :
The first line contains a single integer ‘T’ denoting the number of test cases. The 'T' test cases follow.

The first line of each test case contains two integers separated by single space ‘N’ and ‘K’ denoting the number of elements in the array/list and the length of the subarray.

The second line of each test case contains ‘N’ single space-separated integers denoting the elements of the array/list.
Output Format :
For each test case, print a single line that contains ‘N’ - ‘K’ + 1 space-separated integers denoting the maximum for each subarray in the following sequence:

[0, K-1], [1, K], . . . , [N-K, N-1] where [i, j] denotes the maximum element in the subarray starting from the ith index and ending with jth index.
Note :
You do not need to print anything, it has already been taken care of. Just implement the given function.
Constraints :
1 <= 'T' <= 50
1 <= 'N' <= 10^4
1 <= 'K' <= 'N'
0 <= 'ARR[i]' <= 10^5

Where  'ARR[i]' denotes the ith elements of the given array/list.

Time Limit: 1 sec
Sample Input 1 :
2
5 3
3 6 5 4 3
4 2
7 2 5 4
Sample Output 1 :
6 6 5 
7 5 5
Explanation Of Sample Input 1 :
In the first test case, 3 subarrays of length 3 are possible:
[0, 2], elements in the subarray are: {3, 6, 5} and the maximum is 6
[1, 3], elements in the subarray are: {6, 5, 4} and the maximum is 6
[2, 4], elements in the subarray are: {5, 4, 3} and the maximum is 5

In the second test case, 3 subarrays of length 2 are possible:
[0, 1], maximum of {7, 2} is 7
[1, 2], maximum of {2, 5} is 5
[2, 3], maximum of {5, 4} is 5
Sample Input 2 :
2
5 5
1 2 3 4 5
5 1
3 5 6 2 9
Sample Output 2 :
5
3 5 6 2 9
Explanation Of Sample Input 2 :
In the first test case, 1 subarray of length 5 is possible. The maximum of {1, 2, 3, 4, 5} is 5.

In the second test case, 5 subarrays of length 1 are possible. The maximum of each subarray is {3, 5, 6, 2, 9}, the array/list itself.*/
#include<bits/stdc++.h>
using namespace std;
vector<int> getMaximumOfSubarrays(vector<int> arr, int k)
{   vector<int>ans;
	//    Write your code here
	if(k==1) return arr;
	if(k==arr.size()) return {*max_element(arr.begin(),arr.end())};
    deque<int>dq(k);
    int i=0;
    for(i=0;i<k;++i)
    {
        while(!dq.empty() && arr[i] >= arr[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    for(;i<arr.size();++i)
    {  
         ans.push_back(arr[dq.front()]);
       
        while((!dq.empty()) && dq.front() <= i-k){
            dq.pop_front();
        }

        while((!dq.empty()) && arr[i] >= arr[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
    }

    ans.push_back(arr[dq.front()]);

    return ans;
   	
	
	
}
int main()
{
    vector<int>v={1,2,3,4,5};
    int k = 1;
    vector<int>ans = getMaximumOfSubarrays(v,k);
    for(auto i:ans) cout<<i<<" ";

    
}