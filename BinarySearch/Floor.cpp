#include<bits/stdc++.h>
using namespace std;
/*
 find floor of element -> greatest of smallet element less than k;
 find ceil -> smallet element greater than x;
*/
int Flore(vector<int>v,int k)
{   int ans = -1;
    int s = 0; int e = v.size()-1;
    while (s<=e)
    {
        int m = s+(e-s)/2;
        
        if(v[m] == k) return m;

        if(v[m] < k)
        {
            ans = m;
            s=m+1;
        }
        else{
            e = m-1;
        }
        
    }
    return ans;
}

int Ceil(vector<int>v,int k)
{   int ans = -1;
    int s = 0; int e = v.size()-1;
    while (s<=e)
    {
        int m = s+(e-s)/2;
        
        if(v[m] == k) return m;

        if(v[m] > k)
        {
            ans = m;
            e=m-1;
        }
        else{
            s = m+1;
        }
        
    }
    return ans;
}
int main()
{   
    vector<int>v = {1,2,3,4,8,100,100,12,29};
    int k = 5;
    cout<<Ceil(v,k);
}