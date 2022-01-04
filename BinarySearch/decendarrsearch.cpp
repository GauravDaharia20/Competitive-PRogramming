#include<bits/stdc++.h>
using namespace std;
int binsearch(vector<int>v,int k)
{
    int s = 0; int e = v.size()-1;

    while (s<=e)
    {
        /* code */
        int m = s+(e-s)/2;
        if(v[m] == k)
        {
            return m;
        }
        else if(v[m] > k)
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
    vector<int>v = {10,8,7,6,2,1};
    cout<<binsearch(v,10);
}