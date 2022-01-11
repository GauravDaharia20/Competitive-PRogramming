#include<bits/stdc++.h>
using namespace std;
int LCS(string s1 , string s2, int n, int m)
{
    if(n==0 || m==0)
    {
        return 0;
    }

    if(s1[n-1] == s2[m-1])
    {
        return 1+LCS(s1,s2,n-1,m-1);
    }
    else{
        int a1 = LCS(s1,s2,n-1,m);
        int a2 = LCS(s1,s2,n,m-1);

        return max(a1,a2);
    }
}
int main()
{
    string s1 = "gaurav";
    string s2 = "daharia";
    //ara

    cout<<LCS(s1,s2,s1.size(),s2.size());
}