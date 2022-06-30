#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a = "00011011";
    int zc = 0; int oc = 0;
    int ss = 0;
    for(auto i:a){
        if(i=='0'){
            zc++;
        }
        if(i=='1'){
            oc++;
        }
        if(zc == oc){
            ss++;
            zc = 0;
            oc = 0;
        }
    }
    cout<<ss;
}