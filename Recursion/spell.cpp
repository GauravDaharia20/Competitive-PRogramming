#include<bits/stdc++.h>
using namespace std;

string sp [] = {"zero","one","two","three","four","five","six","seven","eight","nine"};


void spell(int n)
{   //string ans = "";
    if(n == 0) return ;

    int lst = n%10;
    spell(n/10);
    cout<<sp[lst];

}
int main()
{
    int n;
    cin>>n;
    spell(n);
}