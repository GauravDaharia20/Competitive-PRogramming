#include<bits/stdc++.h>
using namespace std;
void generatebracket(string op,int n, int o,int c,int i)
{
    if(i==2*n)
    {
        cout<<op<<endl;
        return;
    }
    if(o < n)
    {
        generatebracket(op+'(',n,o+1,c,i+1);
    }
    if(c < o)
    {
        generatebracket(op+')',n,o,c+1,i+1);
    }
}
int main()
{
    int n;
    cin>>n;
    generatebracket("",n,0,0,0);
} 
