#include<bits/stdc++.h>
using namespace std;
string encode(string s)
{   string ans ;
    int c = 0;
    int cc = s[0];
    for(int i=0;i<=s.size();i++)
    {
        if(s[i]==cc){
            c++;
        }
        else{
            ans+=cc;
            ans+=to_string(c);
            c = 1;
            cc = s[i];
        }
    }
    return ans;
}
int main()
{
    string s;
    cin>>s;
    cout<<encode(s);
}