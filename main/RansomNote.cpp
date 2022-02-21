#include <bits/stdc++.h>
using namespace std;
int main()
{
    string ran = "a";
    string mag = "b";
    int n = ran.size();
    unordered_map<char,int>mp;
    for(auto i:mag){
        mp[i]++;
    }
    for(auto i:ran){
        if(mp[i]!=0)
        {
            mp[i]--;
            n--;

        }
        else{
            continue;
        }
    }
    if(n == 0){
            cout<<true;
    
        }
        else{
            cout<<false;
        }
}