#include<bits/stdc++.h>
using namespace std;
int minjumps(vector<int>v,int n,int i)
{
    if(i >= n-1)
    {
        return 0;
    }
    int ans = INT_MAX;
    int cp = v[i];
    while(cp > 0)
    {
        ans = min(ans,1+minjumps(v,n,i+cp));
        cp --;
    }
    if(ans == INT_MAX) return -1;
    return ans;
}
int main()
{
    vector<int>v = {1,1,1,0,0 };
    //int n = sizeof(a)/sizeof(a[0]);
    int n = v.size();
    int ans = INT_MAX;

    cout<<minjumps(v,n,0);

}