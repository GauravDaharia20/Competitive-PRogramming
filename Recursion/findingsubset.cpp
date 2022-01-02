#include<bits/stdc++.h>
using namespace std;
void subset(string s, string o)
{
    if(s.size()==0)
    {
        cout<<o<<" ";
        return;
    }
    char c = s[0];
    string remain = s.substr(1);
    subset(remain,o+c);
    subset(remain,o);
}
int main()
{
    string s;
    cin>>s;
    subset(s,"");
}