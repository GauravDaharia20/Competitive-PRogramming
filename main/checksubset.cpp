#include<bits/stdc++.h>
using namespace std;
int main()
{

    string s = "codingminutes";
    string s1 = "cines";
    bool f = false;
    int i=0;int j=0;
    while (i<s.length() && j<s1.length())
    {
        if(s[i] == s1[j])
        {   f=true;
            i++;
            j++;
        }
        else{
            f = false;
            i++;
        }
    }
    f==true ? cout<<"y" : cout<<"n";
    





    // map<char,int>mp;
    // for(int i=0;i<s.length();i++)
    // {
    //     mp[s[i]] = i;
    // }
    // bool f=false;
    // for(auto i:s1)
    // {
    //     if(mp.find(i)!=mp.end())
    //     {
    //         f=true;
    //     }
    //     else{
    //         f = false;
    //     }
    // }
    // f==true? cout<<"y":cout<<"n";


}