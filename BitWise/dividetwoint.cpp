/*
You are given two integers ‘dividend’ and ‘divisor’. You are required is to divide the integers without using multiplication, division and modular operators. Your task is to return the quotient after dividing ‘dividend’ by ‘divisor’.
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n1,n2;
    cin>>n1 >>n2;
    int sn = ((n1 < 0) ^ (n2 < 0)) ? -1 : 1;
    int q = 0;
    n1 = abs(n1);
    n2 = abs(n2);
    while (n1 >= n2)
    {
        /* code */
        n1 = n1-n2;
        ++q;
    }
    cout << q*sn;
    
}