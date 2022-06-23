#include<bits/stdc++.h>
using namespace std;
/*find ways to get paired either go single or go paired*/
int numpaired(int n)
{
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(n == 2) return 2;
    return numpaired(n-1) + (n-1) * numpaired(n-2);
}
int main()
{
    int n;
    cin>>n;
    cout<<numpaired(n);
}