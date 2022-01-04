#include<bits/stdc++.h>
using namespace std;
int findmin(vector<int>v)
{   int n = v.size();
    int s = 0; int e = v.size()-1;
    while(s<=e)
    {   
        if(v[s] <=v[e])
        {
            return s;
        }
        int m = s+(e-s)/2;

        int prev = (m-1+n)%n;
        int nxt = (m+1)%n;

        if(v[m] <= v[prev] && v[m]<=v[nxt])
        {
            return m;
        }
        else if(v[s] <=v[m])
        {
            s = m+1;
        }
        else if(v[m] <=v[e])
        {
            e = m-1;
        }
    }
    return -1;
}
int binaryrotatelement(vector<int>v,int st,int et,int k)
{   
        int s = st; int e = et;
        while (s<=e)
        {
            /* code */
            int m = s+(e-s)/2;
            if(v[m] == k)
            {
                return m;
            }
            else if(v[m] <k){
                    s = m+1;
            }
            else{
                e = m-1;
            }

        }

     return -1;   
}
int main()
{
    vector<int>v = {11,12,15,18,2,5,6,8};
    int id = findmin(v);
    //cout<<id;
    if(id!=-1) 
    {
        cout<<binaryrotatelement(v,0,id-1,15)<<endl;
        cout<<binaryrotatelement(v,id+1,v.size()-1,15)<<endl;
    }
   
}