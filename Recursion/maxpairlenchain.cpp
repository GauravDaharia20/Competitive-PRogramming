/*You are given ‘N’ pairs of integers in which the first number is always smaller than the second number i.e in pair (a,b) -> a < b always. Now we define a pair chain as the continuous arrangement of pairs in which a pair (c,d) can follow another pair (a,b) only when b < c.
Find the length of the longest pair chain that can be formed using the given pairs.
Example:
Given Pairs =  [3,4], [1,2], [2,3].

The length of the maximum chain will be 2. The longest chain is [1,2] -> [3,4].
Note:
1. You can select a pair only once.

2. You needn’t use up all the given pairs.

3. You can select pairs in any order. */

#include<bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}
int main()
{
    vector<pair<int, int>>v ={
        {3,4},{1,2},{2,3}
    };

    sort(v.begin(),v.end(),sortbysec);
    int cnt = 1;
    for(auto i:v){
        int s = i.first;
        int e = i.second;

        cout<<s<<" "<<e<<endl;


    }


}