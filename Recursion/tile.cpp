#include<bits/stdc++.h>
using namespace std;
int ways(int n, int m)
{
    if(n < m){
        return 1;
    }
    if(n == m) return 2;
    return ways(n-1,m) + ways(n-m,m);
}
int main()
{
    int n,m;
    cin>>n>>m;
    cout<<ways(n,m);
}