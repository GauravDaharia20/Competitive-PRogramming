#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n1,n2;
    cin>>n1>>n2;
    int cnt = 0;
    while(n1 > 0 || n2 > 0)
    {
        if((n1&1) != (n2&1))
        {
            cnt++;
        }
        n1=n1>>1;
        n2=n2>>1;
    }
    cout<<cnt;
}
