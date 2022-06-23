#include<bits/stdc++.h>
using namespace std;
int fastPower(int a,int n){
    if(n==0) return 1;

    int subprob = fastPower(a,n/2);
    int subsq = subprob * subprob;

    if(n&1){
        return a*subsq;
    }
    return subsq;
}
int main()
{
    int a,n;
    cin>>a>>n;
    cout<<fastPower(a,n);
}