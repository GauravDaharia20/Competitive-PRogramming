#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<vector<int>>v = {
        {1,3},{2,6},{8,10},{15,18}
    };

    sort(v.begin(),v.end());
    
    vector<vector<int>>ans;

    int s = v[0][0];
    int e = v[0][1];

    for(int i=1;i<v.size();i++)
    {
        if(v[i][0] <=e){

            e = max(e,v[i][1]);

        }
        else{
            ans.push_back({s,e});
            s = v[i][0];
            e = max(e,v[i][1]);
        }
    }
    ans.push_back({s,e});

    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }


}