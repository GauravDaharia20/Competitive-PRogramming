#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>v = {1,2,3,4,5};
    int n = v.size();
    vector<int>l(n),r(n);
    l[0]=1;
    r[n-1]=1;

    for(int i=1;i<n;i++)
    {   //cout<<l[i-1]<<" "<<v[i-1]<<endl;
        l[i] = l[i-1] * v[i-1];
    }
    //for(auto i:l) cout<<i<<" ";
    cout<<endl;
    for(int i=n-2;i>=0;i--)
    {
        r[i] = r[i+1] * v[i+1];
    }

   // for(auto i:r) cout<<i<<" ";

    for(int i=0;i<n;i++)
    {
        v[i] = l[i]*r[i];
    }

    for(auto i:v) cout<<i<<" ";
    cout<<endl;





}
