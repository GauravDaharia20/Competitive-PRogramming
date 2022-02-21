#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<vector<int>>v={
        {1,2,3},{4,5,6},{7,8,9}
    };

    for(int i=0;i<v.size();i++){
        for(int j=0;j<i;j++){
            swap(v[i][j] , v[j][i]);
        }
    }
    for(int i=0;i<v.size();i++){
       reverse(v[i].begin(),v[i].end());
    }
    for(auto i:v){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}