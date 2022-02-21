#include<bits/stdc++.h>
using namespace std;
set<vector<int>>st;
vector<vector<int>>ans;
vector<int>sv;
void help(vector<int>v,int t,int sum,int id){
    if(sum == t && sv.size() == 4  && st.find(sv) == st.end()){
        st.insert(sv);
        ans.push_back(sv);
        return;
    }

    for(int i=id;i<v.size();i++)
    {
        sum+=v[i];
        sv.push_back(v[i]);
        help(v,t,sum,i+1);
        sum-=v[i];
        sv.pop_back();
    }

}
int main(){
    vector<int>v = {-5,5,4,-3,0,0,4,-2};
    //sort(v.begin(),v.end());
    int t = 4;
    help(v,t,0,0);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    
}