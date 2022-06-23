#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    stack<char>st;
    
    for(int i=0;i<s.size();i++)
    {
        if(s[i] == ')')
        {
            char t = st.top();
            st.pop();

            int cnt = 0;
            while(t=='('){
                cnt++;
                t = st.top();
                st.pop();
            }

            if(cnt <=1)
            {
                cout<<1;
                break;
            }

        }
        else{
            st.push(s[i]);
        }
    }
    
}