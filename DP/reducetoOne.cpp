/* min ways to reduce given number to 1 by using following steps:
1. n-> n-1 , 2. n=n/2 3. n=n/3;
*/
#include<bits/stdc++.h>
using namespace std;
int x,y,z;
int reducetoOne(int n){
    if(n==1) return 0;

    int ans = INT_MAX;
    if(n%2==0){
        ans = min(ans,reducetoOne(n/2));
    }
    if(n%3==0){
        ans = min(ans,reducetoOne(n/3));
    }
    ans = min(ans,reducetoOne(n-1));
    
    return ans+1;
}
int main(){
    int n;
    cin>>n;
    cout<<reducetoOne(n);
}