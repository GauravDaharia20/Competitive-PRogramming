#include <bits/stdc++.h>
using namespace std;
int main()
{

    vector<int>v = {0,-2,1,2,3,4,5,15,10,5};
    int sum=0; int mxl = 0;
    int k = 15;
    unordered_map<int,int>mp;
    for(int i=0;i<v.size();i++)
    {
        sum+=v[i];

        if(sum == k )
        {
            mxl = i+1;
        }

        if(mp.find(sum) == mp.end())
        {
            mp[sum]=i;
        }

        if(mp.find(sum - k) !=mp.end())
        {
            mxl = max(mxl,i-mp[sum-k]);
        }
    }
    cout<<mxl;

}
