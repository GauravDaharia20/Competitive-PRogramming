#include<bits/stdc++.h>
using namespace std;
int rotateds(vector<int>v,int k)
{   int n = v.size();
    int s =  0; 
    int e = n-1;

    while (s<=e)
    {
        int m = s+(e-s)/2;
        if(v[m]==k) return m;
        
        if (v[m] >=v[s])
        {
            if(k >=v[s] && k<=v[m])
            {
                    e = m-1;
            }
            else{
                s = m+1;
            }
        }
        if(v[m]<=v[e])
        {
            if(k>=v[m] && k<=v[e])  // nt comparing s and m because it is nt monotonic.
            {
                s = m+1;
            }
            else{
                e = m-1;
            }
        }
        
    }
    return -1;
}
int main()
{
    vector<int>v = {4,5,6,7,0,1,2,3};
    int k; cin>>k;
    cout<<rotateds(v,k);
}