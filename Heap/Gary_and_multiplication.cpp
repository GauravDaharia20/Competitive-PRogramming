#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr = {2, 3, 3, 4};
    vector<long long> ans;
    long long f=-1,s=-1,t=-1;
    for(auto i:arr){
        if(i>f){
            t=s;
            s=f;
            f=i;
        }
        else if(i>s){
            t=s;
            s=i;
        }
        else if(i>t){
            t=i;
        }

        if(f==-1 || s==-1 || t==-1){
            cout<<-1<<" ";
        }
        else{
            cout<<f*s*t<<" ";
        }
    }
}