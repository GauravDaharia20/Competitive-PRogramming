#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v = {100, 80, 60, 70, 60, 75, 85};
    vector<int> span(v.size(),0);
    stack<int>st;

    st.push(0);
    span[0]=1;
    for(int i=1;i<=v.size()-1;i++)
    {   int currPrice = v[i];
        while(!st.empty() && v[st.top()] <= currPrice ){
            st.pop();
        }
        if(!st.empty()) span[i] = i-st.top();
        else{
            span[i] = i+1;
        }
        st.push(i);
    }
    for(auto i: span)
    {
        cout<<i<<" ";
    }

}