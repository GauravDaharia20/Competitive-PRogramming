#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>s(n+1);
    stack<int>st;
    for(int i=0;i<s.size();i++)
    {
        cin>>s[i];
    }
    reverse(s.begin(),s.end());
    for(auto i:s)
    {   
        st.push(i);
    }
    int k;
    if(s.size()&1){
        k = s.size()/2;
    }
    else{
        k = (s.size()/2)-1;
        //cout<<k;
    }

    int c = 0;

    while (!st.empty())
    {
        /* code */
        cout<<st.top()<<" ";
        st.pop();c++;
        if(c==k) st.pop();
    }
    
    

    
}