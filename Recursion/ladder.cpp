#include<bits/stdc++.h>
using namespace std;
int ladder(int n)
{   
    if(n<0) return 0;
    if(n==0 || n==1) return 1;
    int x = ladder(n-1);
    int y = ladder(n-2);
    int z = ladder(n-3);
    //cout<<x<<y<<z;
    return x+y+z; 
}
int main()
{
    int n;
    cin>>n;
    cout<<ladder(n);
}