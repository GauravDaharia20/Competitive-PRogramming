#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    stack<char>st;
    string ans;
    st.push(s[0]);
    ans+=s[0];
    for(int i=0;i<s.size();i++)
    {
        if(st.top()!=s[i]){
            st.push(s[i]);
            ans+=s[i];
        }
    }
    while (!st.empty())
    {
        /* code */
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<ans;
    
}