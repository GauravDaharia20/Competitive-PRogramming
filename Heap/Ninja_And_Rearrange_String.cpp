/*Ninja has been given a string ‘STR’ and an integer ‘D’. Ninja has to rearrange the string ‘STR’ such that the same characters are present at least ‘D’ distance from each other.
If it is possible to rearrange the string ‘STR’, then return true; otherwise, print false.
Note :
The string ‘STR’ contains only lowercase alphabet characters.
For example :
If ‘STR’ = “aaadbbcc” and ‘D’ = 2.
Then one of the possible solution is “abacabcd”. 
Input Format :
The first line contains a single integer ‘T’ representing the number of test cases. 

The first line of each test case will contain two single space-separated integers ‘N’ and ‘D’ which denote the size of the ‘STR’ and the distance such that the same characters are present at least ‘D’ distance from each other, respectively.

The next line of each test case contains the string ‘STR’.
Output Format :
For each test case, print "true" if it is possible to rearrange the string ‘STR’, otherwise, print "false" without quotes.

Output for every test case will be printed in a separate line.
Note :
You don’t need to print anything; it has already been taken care of. Just implement the given function.
Constraints :
1 <= ‘T’ <= 50
1 <= ‘N’ <= 10000
1 <= ‘D’ <= 26
‘STR’ = {a - z}

Time limit: 1 sec*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s="aaadbbcc";
    int d = 0;
    int l = s.size();
    unordered_map<char,int>mp;
    for(auto i:s){
        mp[i]++;
    } 
    string ans;
    priority_queue<pair<char,int>>pq;
    for(auto i:mp){
        pq.push({i.first,i.second});
    }
    while(!pq.empty()){
        vector<char>tmp;
        int sl = min(d,l);
        for(int i=0;i<sl;i++){
            if(pq.empty()){
                cout<<0;break;
            }
            pair<char,int>tval = pq.top(); pq.pop();
            char c = tval.first;
            int val = tval.second;
            ans+=c;
            mp[c]--;
            l--;
        }
        for(auto i:tmp){
            cout<<i<<" ";
            pq.push({i,mp[i]});
        }
        
    }


}