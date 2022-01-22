#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<vector<int>>ans = {
        {1,1,1},
        {1,0,1},{
            1,1,1
        }
    };

    int r = ans.size();
    int c = ans[0].size();

    vector<bool>rows(r,false);
    vector<bool>cols(c,false);

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(ans[i][j] == 0){
                rows[i] = true;
                cols[j] = true;
            }
        }
    }

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(rows[i]==true || cols[j] == true){
               ans[i][j] = 0;
            }
        }
    }

    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

}