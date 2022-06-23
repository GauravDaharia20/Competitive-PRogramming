// memmoisation
#include<bits/stdc++.h>
using namespace std;
vector<int>memo;
int cnt = 0;
int fibo(int n){
    cnt++;
    if(n<=2) return 1;
    if(memo[n]!=-1){
        return memo[n];
    }
    return memo[n] = fibo(n-1)+fibo(n-2);
}
int main(){
    int n;
    cin>>n;
    memo.resize(n+1,-1);
    cout<<fibo(n)<<endl;
    cout<<cnt<<endl;

}