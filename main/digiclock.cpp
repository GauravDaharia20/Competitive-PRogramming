#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n ;
    cin>>n;
    string h = to_string(n/60);
    string m = to_string(n%60);
    if(m.length()==1)
    {
        m = "0"+m;
    }
    string s = h+":"+m;
    cout<<s;
}