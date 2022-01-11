#include <bits/stdc++.h>
using namespace std;
vector<int> twoSum(vector<int>& v, int target) {
        
        map<int,int>mp;
        for(int i=1;i<=v.size();i++)
        {
            mp[v[i]] = i;
        }
        
        for(auto i:v)
        {
            int remain = target-i;
            if(mp.find(remain)!=mp.end())
            {
                return {mp[i],mp[remain]};
            }
        }
        return {-1,-1};
    }
int main()
{
    vector<int>v = {2,7,11,15};
    int target = 9;

    vector<int>ans = twoSum(v,target);
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
       
}
