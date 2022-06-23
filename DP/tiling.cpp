#include<bits/stdc++.h>
using namespace std;
int tile(int n){
    if(n<=3) return 1;
    return tile(n-1) + tile(n-4);
}
int main()
{
    int n;
    cin>>n;
    cout<<tile(n);

}