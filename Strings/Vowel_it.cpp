#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a = "abhishek";
    string ans;
    set<char>st = {'a','e','i','o','u'};
    for(auto i:a){
        if(st.find(i)!=st.end()){
            ans+=i;
        }
    }
    cout<<ans;
}