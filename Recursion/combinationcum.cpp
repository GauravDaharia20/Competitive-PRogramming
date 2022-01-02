#include<bits/stdc++.h>
using namespace std;
vector<int>ans;
vector<vector<int>>sol;
void help(vector<int>v,int t,int i)
{
    if(i==v.size())
    {
        if(t ==0) sol.push_back(ans);
        return;
    }
    if(v[i] <= t)
    {
        ans.push_back(v[i]);
        help(v,t-v[i],i);
        ans.pop_back();
    }
    help(v,t,i+1);

}
int main()
{
    vector<int>v = {2,3,6,7};
    int t = 7;
    help(v,t,0);
    // for(auto i:ans)
    // {
    //     cout<<i<<" ";
    // }
    for(int i=0;i<sol.size();i++)
    {
        for(int j=0;j<sol[i].size();j++)
        {
                cout<<sol[i][j]<<" ";
        }
        cout<<endl;
    }

}