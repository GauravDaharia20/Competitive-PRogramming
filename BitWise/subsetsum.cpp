#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>num = {1,2,3};
    vector<int>q = {5,3,8};
    bitset<10>b;
    b[0] = 1;
    for(int i=0;i<num.size();i++){
        bitset<10>msk = (b<<num[i]);
        b = b|msk;
    }
    for(auto i:q){
        if(b[i]==1){
            cout<<1;
        }
        else{
            cout<<0;
        }
    }
}