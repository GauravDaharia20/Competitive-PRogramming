#include<bits/stdc++.h>
using namespace std;
int lower(vector<int>&v,int k)
{
    int s = 0; int e = v.size()-1;
    int ans = -1;

    while (s<=e)
    {
        int m = s+(e-s)/2;
        if(v[m] == k)
        {
            ans = m;
            e = m-1;
        }
        else if(v[m] > k){
            e = m-1;
        }
        else{
            s= m+1;
        }

    }
    return ans;
    
}

int upper(vector<int>&v,int k)
{
    int s = 0; int e = v.size()-1;
    int ans = -1;

    while (s<=e)
    {
        int m = s+(e-s)/2;
        if(v[m] == k)
        {
            ans = m;
            s = m+1;
        }
        else if(v[m] < k){
            s = m+1;
        }
        else{
            e = m-1;
        }

    }
    return ans;
    
}
int main()
{
    vector<int>v = {0,1,1,1,1,2,2,2,3,4,4,5,10};
    cout<<upper(v,2) - lower(v,2)+1;
    
}