#include<bits/stdc++.h>
using namespace std;
bool comp(string s1,string s2)
{
   string xy = s1.append(s2);
   string yx = s2.append(s1);
   return xy.compare(yx);
}
int main()
{
    vector<string>v={"10","11","20","30","3"};
    sort(v.begin(),v.end(),comp);
    for(auto i:v)
    {
        cout<<i<<" ";
    }
}