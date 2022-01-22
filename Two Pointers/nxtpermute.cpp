#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>dis = {1,1,5};
    int cnt = 0;
    do{
        next_permutation(dis.begin(),dis.end());
        for(auto i:dis){
            cout<<i<<" ";
        }
    }while(cnt--);
    
}