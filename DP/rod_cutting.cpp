#include<bits/stdc++.h>
using namespace std;
int help(vector<int> v,int n){

    if(n == 0) {
        return 0;
    }
    int ans = INT_MIN;
    for(int i=1;i<=n;i++){

        int t = v[i-1] + help(v,n-i);
        ans = max(ans,t);
    }
    return ans;
}
int main()
{
    vector<int>v = {3,5,8,9,10,17,17,20};
    
    cout<<help(v,v.size());
}