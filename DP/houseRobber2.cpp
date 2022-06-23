/*Mr. X is a professional robber planning to rob houses along a street.
Each house has a certain amount of money hidden.
All houses along this street are arranged in a circle.
That means the first house is the neighbor of the last one.
Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.
You are given an array/list of non-negative integers 'ARR' representing the amount of money of each house.
Your task is to return the maximum amount of money Mr. X can rob tonight without alerting the police.*/
#include <bits/stdc++.h>
using namespace std;

int help(vector<int> t, int n)
{

    int prev = t[0];
    int prev2 = 0;
    for (int i = 1; i < n; i++)
    {
        int take = t[i];
        if (i > 1)
        {
            take +=prev2;
        }
        int ntake = 0 + prev;
        int cur = max(take, ntake);
        prev2 = prev;
        prev = cur;
    }
    return prev;
}
int main()
{
    vector<int> v = {1, 3, 2,1};
    vector<int> t1, t2;
    for (int i = 0; i < v.size(); i++)
    {
        if (i != 0)
        {
            t1.push_back(v[i]);
        }
        if (i != v.size() - 1)
        {
            t2.push_back(v[i]);
        }
    }
    //for(auto i:t1) cout<<i<<" ";
    //cout<<endl;
     //for(auto i:t2) cout<<i<<" ";
     int a1 = help(t1,t1.size());
     int a2 = help(t2,t2.size());
      cout<<a1<<" "<<a2;
//     cout<<max(a1,a2);
}