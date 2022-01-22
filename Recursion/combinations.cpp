#include<bits/stdc++.h>
using namespace std;
void help(int n, vector<vector<int>>&ans, vector<int>&sv,int id,int k){
    if(sv.size() == k){
        ans.push_back(sv);
        return;
    }

    for(int i=id;i<=n;i++)
    {
        sv.push_back(i);
        help(n,ans,sv,i+1,k);
        sv.pop_back();
    }


}
int main()
{
    int n = 4;int k=2;
    vector<vector<int>>ans;
    vector<int>sv;
    help(n,ans,sv,1,k);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}