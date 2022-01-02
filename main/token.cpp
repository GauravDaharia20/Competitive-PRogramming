#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    getline(cin,s);
    stringstream buff(s);
    string token;
    vector<string>tokens;
    while (getline(buff,token,' '))
    {
        /* code */
        tokens.push_back(token);
    }
    for(auto i:tokens)
    {
        cout<<i<<",";
    }
}