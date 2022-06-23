/*You are given a string 'S', check if there exists any permutation of the given string that is a palindrome.*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s = "aab";
    unordered_map<char,int>m;
    for(auto i:s)
    {
        m[i]++;
    }
    int oo = 0;
    for(auto i = m.begin();i!=m.end();i++){
        if((i -> second & 1) ){
            oo++;
            if(oo > 1){
                cout<<"f"; break;
            }
        }
    }
    cout<<"t";
}