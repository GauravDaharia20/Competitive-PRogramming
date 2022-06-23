#include<bits/stdc++.h>
using namespace std;
int partyPair(int n){
    if(n<=1) return 1;
    return partyPair(n-1) + (n-1)*partyPair(n-2);
}
int main()
{
    int n;
    cin>>n;
    cout<<partyPair(n);
}