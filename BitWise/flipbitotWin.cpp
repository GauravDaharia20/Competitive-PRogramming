#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n = 838;
    int currlen = 0 , prevlen = 0 , maxlen = 0;
    while(n!=0)
    {
        if((n&1)==1)
        {
            currlen++;
        }
        else if((n&1)==0)
        {
            prevlen = ((n&2)==0) ? 0 : currlen;

            currlen = 0;
        }
        maxlen = max(maxlen,currlen+prevlen);
        n=n>>1;
    }
    cout<<maxlen+1;
}