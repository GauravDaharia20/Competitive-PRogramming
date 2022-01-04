#include<bits/stdc++.h>
using namespace std;
/*
    find element in nearly sorted array -.> i,i+1,i-1
*/
int searchbin(vector<int>v,int k)
{   int n = v.size();
    int s = 0; int e = v.size()-1;
    while (s<=e)
    {
        /* code */
        int m = s+(e-s)/2;
        
        if(v[m] == k)
        {
            return m;
        }

        if(m-1 >=s && v[m-1]==k) return m-1;
        if(m+1 <=e && v[m+1]==k) return m+1;

        if(v[m] < k)
        {
            s = m+1;
        }
        else{
            e = m-1;
        }
        

    }
    return -1;
}
int main()
{
    vector<int>v = {5,10,30,20,40};
    cout<<searchbin(v,40);
}