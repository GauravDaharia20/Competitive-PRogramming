#include<bits/stdc++.h>
using namespace std;
int partition(vector<int>&v,int s ,int e)
{   int i = s-1;
    int p = v[e];
    for(int j=s;j<e;j++)
    {
        if(v[j] < p)
        {   
            i++;
            swap(v[i],v[j]);
        }
    }
    swap(v[i+1],v[e]);
    return i+1;
}
int quicksort(vector<int>v,int s,int e,int k)
{
    int p = partition(v,s,e);
    if(p == k)
    {
        return v[p];
    }
    else if(k < p)
    {
        return quicksort(v,s,p-1,k);
    }
    else{
        return quicksort(v,p+1,e,k);
    }

}
int main()
{
    vector<int>v = {10,5,2,0,7,6,4};
   cout<< quicksort(v,0,v.size()-1,1);
}