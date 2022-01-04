#include<bits/stdc++.h>
using namespace std;
int binaryrotatesearch(vector<int>v)
{   int n = v.size();
    int s = 0; int e = v.size()-1;
    while (s<=e)
    {   
        if(v[s] <=v[e])
        {
            return v[s];
        }
        int m = s+(e-s)/2;
        int p = (m-1+n)%n;
        int nx = (m+1)%n;
        if( v[m] <=v[nx] && v[p]>=v[m])
        {
            return v[m];
        }
        else if(v[s] <= v[m])
        {
            s = m+1;
        }
        else if(v[m] <= v[e]){
            e = m-1;
        }
        
    }
    return -1;
}
int main()
{
    vector<int>v = {11,12,15,18,2,5,6,8};
    cout<<binaryrotatesearch(v);
}