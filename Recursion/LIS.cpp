#include<bits/stdc++.h>
using namespace std;
int LIS(vector<int>v,int i,int n,int p)
{
    if( i == n){
        return 0;
    }

    int exclude = LIS(v,i+1,n,p);
    int include = 0;
    if(v[i] > p)
    {
        include = LIS(v,i+1,n,v[i])+1;
    }

    return max(exclude , include);

}
int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }

    cout<<LIS(v,0,v.size(),INT_MIN);
}