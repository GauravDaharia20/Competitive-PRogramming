#include<bits/stdc++.h>
using namespace std;
void printSubset(string s,string o,vector<string>&lis)
{
    if(s.empty())
    {
        lis.push_back(o);
        return;
    }
    //include
    printSubset(s.substr(1),o+s[0],lis);
    //exclude
    printSubset(s.substr(1),o,lis);

}
int main()
{
    string s;
    cin>>s;
    string o;
    vector<string>lis;
    printSubset(s,o,lis);
    set<string>st(lis.begin(),lis.end());
    for(auto i:st){
        cout<<i<<" ";    
    }
    cout<<endl;
    cout<<st.size();
}