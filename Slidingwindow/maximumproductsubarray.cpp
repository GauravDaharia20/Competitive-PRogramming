#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>v = {0,2};
    int minval = v[0];
    int maxval = v[0];

    int ans = v[0];

    for(int i=1;i<v.size();i++)
    {
        if(v[i] < 0){
            swap(minval,maxval);
        }
        minval = min(v[i],v[i] * minval);
        maxval = max(v[i] , v[i]*maxval);

        ans = max(ans,maxval);
    }
    cout<<ans;
   
}