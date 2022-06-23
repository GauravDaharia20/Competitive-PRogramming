#include<bits/stdc++.h>
using namespace std;
string removeKDigits(string s,int k)
{   stack<char>st;
    int n = s.size();
    // remove the all maxima values
    for(int i=0;i<n;i++)
    {
        while(k > 0 && !st.empty() && st.top() > s[i]){
            st.pop();
            k--;
        }
        if(!st.empty() || s[i]!='0'){
            st.push(s[i]);
        }
    }

    //edge case when everthing is in ascending order
    while (!st.empty() && k--)
    {
        /* code */
        st.pop();
    }

    if(st.empty()) return "0";

    while (!st.empty())
    {
        /* code */
        s[n-1]=st.top();
        st.pop();
        n--;
    }
    return s.substr(n);
    
}
int main()
{
    string s;
    cin>>s;
    int k; cin>>k;
    cout<<removeKDigits(s,k);
}