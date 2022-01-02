#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s = "abc";
    string ans;
     
    int cnt=1;
    char curr = s[0];
    for(int i=1;i<=s.length();i++)
    {
        
        if(s[i] == curr) cnt++;
        else{
            ans+=curr;
            ans+=to_string(cnt);
            cnt=1;
            curr = s[i];
        }
    }
    if(ans.length() > s.length()) cout<<s;
    else cout<<ans;
}