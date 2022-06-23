#include<bits/stdc++.h>
using namespace std;
int getIthbit(int n,int i)
{
    int msk = (1<<i);
    return (n&msk) > 0 ? 1:0;
}
void setIthbit(int &n,int i)
{
    int msk = (1<<i);
    n = n|msk;
}
int clearbit(int n,int i){

    int msk = ~(1<<i);
    return (n&msk);
}

void updateIthbit(int &n,int i,int v){

    n = clearbit(n,i);
    int msk = (v<<i);
    n=n|msk;


}

int clearLastIbits(int n , int i)
{
    int mask = (~0) << i;
    return n&mask;
}

int clearbitRange(int n,int i,int j){
    int a = (~0)<<(j+1);
    int b = (1<<i)-1;
    int mask = a|b;
    return n&mask;
}

int replacebit(int n,int m,int i,int j){
    m = m<<i;
    n = clearbitRange(n,i,j);
    return n|m;
}


long int fastExpo(long int a,long int n){
    long int ans =1 ;
    while(n > 0)
    {
        long int lst = (n&1);
        if(lst){
            ans*=a;
        }
        a=a*a;
        n=n>>1;

    }
    return ans;
}

int convertToBinary(int n)
{
    int ans = 0;
    int p = 1;
    while(n > 0)
    {
        int lst = (n&1);

        ans += p*lst;

        p = p*10;
        n = n>>1;
        
    }
    return ans;
}
int main()
{   

        // left shift -> a<<b = a*2^b
        //right shift -> a >> b = a/2^b


        //even and odd
        // int n;
        // cin>>n;

        cout<<fastExpo(12,25)%1007;


        // if(x&1){
        //     cout<<"odd";
        // }
        // else{
        //     cout<<"even";
        // }


        //getting the ith bit of a number
        //cout<<getIthbit(x,i)<<endl;
        //setIthbit(x,i);
        //cout<<x<<endl;

        // updateIthbit(x,i,1);
        // cout<<x;

       // cout<<replacebit(x,y,i,j);


        //check a power of 2

        // if((n&(n-1))==0) cout<<"2";
        // else cout<<"not 2";
        // int cnt = 0;
        // while(n > 0){
        //     cnt+=(n&1);
        //     n = n>>1;
        // }
        // cout<<cnt;









}