#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>ans;
void help(vector<int>vals,int t,vector<int>tb,int id){
    if(t == 0 || t<=0){
        ans.push_back(tb);
        return;
    }

    for(int i=id;i<vals.size();i++){
        if(i!=id && (vals[i]==vals[i-1])){
            continue;
        }
        tb.push_back(vals[i]);
        help(vals,t-vals[i],tb,i+1);
        tb.pop_back();

    }
    
    
}
int main(){
    vector<int>vals = {10,1,2,7,6,1,5};
    vector<int>tb;
    int t = 8;
    sort(vals.begin(),vals.end());
    help(vals,t,tb,0);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    

    
}