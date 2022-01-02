#include<bits/stdc++.h>
using namespace std;
int  expo(int a,int b)
{
    //base
    if(b==0)
    {
       return 1;
       
    }
   return (a*expo(a,b-1));
   
}
int main()
{
    int a,b;
    cin>>a>>b;
    cout<< expo(a,b);
}