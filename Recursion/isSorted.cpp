#include<bits/stdc++.h>
using namespace std;
bool isSorted( int *v , int n)
{
    if(n==1 || n==0) return true;
    if(v[0] < v[1] && isSorted(v+1,n-1)){

            return true;
    }
    return false;
}
int main()
{
    int n;
    cin>>n;
    int v[n];
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }

    cout<<isSorted(v,n);


}