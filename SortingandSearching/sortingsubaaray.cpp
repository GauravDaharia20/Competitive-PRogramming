#include<bits/stdc++.h>
using namespace std;
int main()
{   pair<int,int>p;
    vector<int>a = {0,2,4,7,7,10,11,12,13,14,16,19,29};
    vector<int>b(a);
    sort(a.begin(),a.end());
    cout<<(a==b);
    
    // int i=0;
    // while(a[i]==b[i])
    // {
    //     i++;
    // }

    // p.first = i;
    // cout<<p.first;

    // i = a.size()-1;

    // while(a[i]==b[i])
    // {
    //     i--;
    // }

    
    // p.second = i;
    // cout<<p.second;

}