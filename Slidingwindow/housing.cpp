#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>v = {1,1,1};
    int n = v.size();
    int k = 2;
    int ps = 0;
    int cnt=0;
    // int i=0;int j=0;int cs=0;
    // while(j<v.size())
    // {   
    //     cs+=v[j];
    //     j++;

    //     while(cs > k && i<j)
    //     {
    //         cs = cs - v[i];
    //         i++;
    //     }

    //     if(cs == k)
    //     {   cnt++;
    //         cout<<i<<" "<<j-1<<endl;
    //     }
    // }
    // cout<<cnt;

    map<int,int>mp;
    mp[0]++;
    for(int i=0;i<n;i++)
    {
        ps+=v[i]; cout<<"ps"<<ps<<" ";cout<<endl;
        cnt+=(mp[ps-k]); cout<<"cnt"<<cnt<<" "; cout<<endl;
        mp[ps]++; 

    }
    cout<<cnt;
}