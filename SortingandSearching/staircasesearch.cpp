#include<bits/stdc++.h>
using namespace std;
pair<int,int> check(vector<vector<int>>&v,int n,int k)
{   if(n==0) return {-1,-1};
    int s = v[0][0];
    int l = v[n-1][n-1];
    if(s >k || l<k) return {-1,-1};

    int i=0;int j=n-1;

    while(i<n && j>=0)
    {
        if(v[i][j] == k)
        {
            return {i,j};
        }
        else if(v[i][j] > k)
        {
            j--;
        }
        else{
            i++;
        }
    }

    return {-1,-1};
}
int main()
{
    vector<vector<int>>v = {
        {1,4,9},{2,5,10},{6,7,11}


    };
    pair<int,int>p = check(v,3,10);
    cout<<p.first<<" "<<p.second;
}