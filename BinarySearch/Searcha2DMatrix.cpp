#include<bits/stdc++.h>
using namespace std;
bool search(vector<vector<int>>v , int t){
    int r = v.size(); int c = v[0].size();
    int s = v[0][0];
    int e = v[r-1][c-1];

    if( s > t || e < t ){
        return false;
    }

    int i=0; int j = r-1;
    while(i<r && j>=0)
    {
        if(v[i][j] == t){
            return true;
        }
        if(v[i][j] > t){
            j--;
        }
        else{
            i++;
        }
    }
    return false;
}
int main()
{
    vector<vector<int>>v = {
        {1,3,5,7},{10,11,16,20},{23,30,34,60}
    };

    int t = 3;
    cout<<search(v,t);
}