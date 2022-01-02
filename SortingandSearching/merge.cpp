#include<bits/stdc++.h>
using namespace std;
void merge(vector<int>&v,int s,int e)
{   vector<int>ans;
    int i=s;
    int m = s+(e-s)/2;
    int j = m+1;

    while(i<=m && j<=e)
    {
        if(v[i] <= v[j])
        {
            ans.push_back(v[i]);i++;
        }
        else{
            ans.push_back(v[j]); j++;
        }
    }

    while(i<=m)
    {
        ans.push_back(v[i++]);
    }

    while(j<=e)
    {
        ans.push_back(v[j++]);
    }
    int k = 0;
    for(int id=s;id<=e;id++)
    {
        v[id] = ans[k++];
    }

    return;
}
void mergesort(vector<int>&v,int s,int e)
{
    if(s>=e) return;
    int m = s+(e-s)/2;
    mergesort(v,s,m);
    mergesort(v,m+1,e);
    merge(v,s,e);
}
int main()
{
    vector<int>v = {10,5,2,0,7,6,4};
    mergesort(v,0,v.size()-1);

    for(auto i:v)
    {
        cout<<i<<" ";
    }

}