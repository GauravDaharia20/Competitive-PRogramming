#include<bits/stdc++.h>
using namespace std;
int merge(vector<int>&v,int s,int e)
{   vector<int>ans;
    int i=s;
    int m = s+(e-s)/2;
    int j = m+1;
    int cnt=0;
    while(i<=m && j<=e)
    {
        if(v[i] <= v[j])
        {
            ans.push_back(v[i]);i++;
        }
        else{
            cnt+=(m-i+1);
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

    return cnt;
}
int mergesort(vector<int>&v,int s,int e)
{
    if(s>=e) return 0;
    int m = s+(e-s)/2;
    int c1 = mergesort(v,s,m);
   int c2 =  mergesort(v,m+1,e);
    int ci = merge(v,s,e);

    return c1+c2+ci;
}
int main()
{
    vector<int>v = {0,5,2,3,1};
    cout<<mergesort(v,0,v.size()-1);


}