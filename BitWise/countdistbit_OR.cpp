/*
You are given an array consisting of N positive integers, your task is to count the number of distinct possible values that can be obtained by taking the bitwise OR of the elements of all possible subarrays of the given array
*/
#include<bits/stdc++.h>
using namespace std;
void getsubarray(vector<int>v,int s,int e)
{   
    if(e == v.size()) return;

    else if(s > e){
        getsubarray(v,0,e+1);
    }
    else{
        int ans = 1;
        for(int i=s;i<e;i++)
    {   
        // cout<<v[i]<<","; 
        ans |=v[i];
    }ans|=v[e];
    cout<<ans<<endl;
    
    getsubarray(v,s+1,e);
    }

    return;
    
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
    getsubarray(v,0,0);
}