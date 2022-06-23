#include<bits/stdc++.h>
using namespace std;
int main()
{   int cnt = 0;
    vector<int>v={1,0,0,1,0};
    for(int i=0;i<v.size();i++){
        if(v[i]==1){
            cnt++;
            v[i]=-1;
        }
        else{
            v[i]=1;
        }
    }
    for(auto i:v) cout<<i<<" ";
    int ans = 0;
    int sum = 0;
    for(auto i:v){
        sum+=i;
        ans = max(ans,sum);
        sum = max(sum,0);
    }
    cout<<ans+cnt;
}