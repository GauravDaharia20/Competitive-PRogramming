#include<bits/stdc++.h>
using namespace std;
int main()
{   stack<int>st;
    vector<int>v = {100,80,60,70,60,75,85};
    st.push(0);
    // int ans[1000]={0};
    // ans[0] = 1;
    vector<int>ans;
    ans.push_back(1);
    for(int i=1;i<=v.size()-1;i++)
    {
           int cp = v[i];
           while(!st.empty() && v[st.top()] <=cp)
           {
               st.pop();
           }
           if(!st.empty())
           {
               int ph = st.top();
               ans.push_back(i-ph);
           }
           else{
               ans.push_back(i+1);
           }
           st.push(i);
    }
    for(auto i:ans) cout<<i<<" ";
}