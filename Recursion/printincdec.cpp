#include<bits/stdc++.h>
using namespace std;

void incrementcnt(int n)
{  
    if(n==0){
        return;
    }
    incrementcnt(n-1);
    cout<<n<<" ";


}

void decrementcnt(int n)
{
   if(n==0) return;
   cout<<n<<" ";
   decrementcnt(n-1);


}

int main()
{
    int n;
    cin>>n;
    incrementcnt(n);
    cout<<endl;
    n=n;
    decrementcnt(n);

}