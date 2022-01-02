#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s= "abcaabcdba";
    set<char>st;
    int l=0;int r=0;
    int len = 0;

    while(r<s.length())
    {
        if(st.find(s[r])!=st.end())
        {
            len=max(len,(r-l+1));
            st.insert(s[r]);
            r++;
        }
        
    }

}