#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n1,n2,n3,n4;
    cin>>n1>>n2;
    cin>>n3>>n4;
    int v1 = (n1+n3);
    int v2 = (n2+n4);
    if(v1 <=23 && v2 > 60 ){
        cout<<v1%23 +1  <<" ";
        cout<<(v2)%60<<" ";
    }
    else if(v1 <=23 && v2 <60 ){
        cout<<(v1)%23<<" ";
        cout<<(v2)%60<<" ";
    }

    if(v1 >=23 && v2 <60)
    {
        v1 = abs(v1-23);
        cout<<(v1)%23<<" ";
        cout<<(v2)%60<<" ";
    }

    if(v1 <=23 && v2> 60)
    {
        cout<<(v1%23)+1<<" ";
        cout<<(v2%60)<<" ";

    }

    
}