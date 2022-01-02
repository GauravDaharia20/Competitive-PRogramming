#include<bits/stdc++.h>
using namespace std;
bool comp(string s1 , string s2)
{
    string xy = s1.append(s2);
    string yx = s2.append(s1);

    return xy < yx;
}
int main()
{   string s;
    vector<string>v = {"c","cb","cba"};
    sort(v.begin(),v.end(),comp);
    for(auto i:v) s+=i;
    cout<<s;


}