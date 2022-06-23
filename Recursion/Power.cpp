#include<bits/stdc++.h>
using namespace std;
int Fastpower(int n,int p)
{
    if(p == 0) return 1;
    int subs = Fastpower(n,p/2);
    int subsq = subs * subs;
    if(p&1){
        return n * subsq;
    }
    return subs;
}
int main()
{
    int n,p;
    cin>>n>>p;
    cout<<Fastpower(n,p);
}