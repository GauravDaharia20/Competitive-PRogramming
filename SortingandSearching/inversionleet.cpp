#include<bits/stdc++.h>
using namespace std;
vector<int>ans;
int merge(vector<int>&v,int s,int e)
{   int m = s+(e-s)/2;
    int l=0; int r = m+1;
    int cnt=0;
    vector<int>tmp;

    while(l<=m && r<=e)
    {
        if(v[l]<=v[r])
        {
            tmp.push_back(v[l]);
            l++;
        }
        else{
            cnt+=(m-l+1);
            tmp.push_back(v[r]);
            r++;
        }
    }

    while(l<=m)
    {
        tmp.push_back(v[l++]);
    }

    while (r<=e )
    {
        /* code */
        tmp.push_back(v[r++]);
    }

    int k=0;
    for(int i=s;i<=e;i++)
    {
        v[i] = tmp[k++];
    }
    return cnt;
    

}
int mergesort(vector<int>&v,int s, int e)
{
    if(s >= e) return 0 ;
    int m = s+(e-s)/2;
    int c1 = mergesort(v,s,m);
    int c2 = mergesort(v,m+1,e);
    int ci = merge(v,s,e);
    ans.push_back(c1);
    ans.push_back(c2);
    ans.push_back(ci);
    
}
int main()
{
    vector<int>v = {5,2,6,1};
    int a = mergesort(v,0,v.size()-1);

    for(auto i:ans) cout<<i<<" ";
}