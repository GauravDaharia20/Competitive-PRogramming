#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>a = {1, 2, 3, 3 };
    sort(a.begin(),a.end(),greater<int>());
    cout<<a[0]<<" "<<a[1]<<endl;
    if(a[1]==a[0]){
        cout<<a[2]%a[1];
    }
}