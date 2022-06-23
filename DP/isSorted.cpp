#include<bits/stdc++.h>
using namespace std;
bool isSorted(int *a,int n){
    if(n==1 || n==0) return true;
    if(a[0] < a[1] && isSorted(a+1,n-1)){
        return true;
    }
    return false;
}
int main()
{
    int a[]={1,2,3,5,4,6};
    cout<<isSorted(a,6);
}