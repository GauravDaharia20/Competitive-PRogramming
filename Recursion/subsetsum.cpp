#include <bits/stdc++.h>
using namespace std;

int check(vector<int> v,int n, int i, int s)
{
    if (i == v.size())
    {
        if (s == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    
    }
    int inc = check(v,n,i+1,s-v[i]);
    int exe = check(v,n,i+1,s);

    return inc+exe;
}
    int main()
    {
        vector<int>v = {2,3,6,7};
        int s = 7;
        cout<<check(v,v.size(),0,s);
        
    }
