#include<bits/stdc++.h>
using namespace std;
float square(int n,int p)
{
    int s = 0;
    int e = n;
    float ans=0.0;
    while(s<=e)
    {
        int m = s+(e-s)/2;
        if(m*m == n)
        {
            return m;
        }
        if(m*m < n)
        {
            ans = m;
            s = m+1;
        }
        else{
            e=m-1;
        }
    }
    //cout<<ans;

    // linear search

    float inc = 0.1;
    for(int x=1;x<=p;x++)
    {
            while (ans*ans <=n)
            {
                ans+=(inc);
            }
            ans = ans-inc;
            inc = inc/10.0;
    }

    return ans;
}
int main()
{
        int n,p;
        cin>>n>>p;
        cout<<square(n,p);
} 
