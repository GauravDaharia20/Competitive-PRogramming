#include<bits/stdc++.h>
using namespace std;
int partition(vector<int>&v,int s,int e)
{
    int i = s-1;
   // int j = s;
    int pivot = v[e];

    for(int j=s;j<e;j++)
    {
        if(v[j] <pivot)
        {   i++;
            swap(v[i],v[j]);
        }
    } 
    swap(v[i+1],v[e]);
    return i+1;
}
void quicksort(vector<int>&v,int s,int e)
{
    if(s>=e) return ;

    int p = partition(v,s,e);
    quicksort(v,s,p-1);
    quicksort(v,p+1,e);
}
int main()
{
    vector<int>v = {5,6,0,1,8};
    quicksort(v,0,v.size()-1);
    for(auto i:v)
    {
        cout<<i<<" "; 
    }
}