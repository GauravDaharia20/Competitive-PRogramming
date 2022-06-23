#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    string s = to_string(n);
    stack<char>st;
    for(auto i:s)
    {
        st.push(i);
    }
    s = "";
    //reverse(st);
    while(!st.empty()){
        s+=st.top();
        st.pop();
    }
    stringstream geek(s);
    int x = 0;
    geek >> x;
    cout<<x;

}