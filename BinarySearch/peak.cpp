#include<bits/stdc++.h>
using namespace std;
/*
    peak is greater than both left nd right;
*/
int findPeak(vector<int>v,int s,int e)
{
   
    int m = s+(e-s)/2;

    if((m==0 || v[m-1] <= v[m]) &&  (m==v.size()-1 || v[m+1] <= v[m]))
    {
        return v[m];
    }

    else if(m > 0 && v[m-1] > v[m])
    {
        return findPeak(v,s,m-1);
    }
    else{
        return findPeak(v,m+1,e);
    }
}
int main()
{
    vector<int>v = {1,3,8,12,9,2};
    cout<<findPeak(v,0,v.size()-1);
}