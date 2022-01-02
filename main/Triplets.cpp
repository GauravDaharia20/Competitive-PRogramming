#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>v={-1,0,1,2,-1,-4};
    int sum=0;
    vector<vector<int>>ans;
    //1.sort 2. fix one and use 2 pointer on remaining array
    sort(v.begin(),v.end());
    for(int i=0;i<=v.size()-3;i++)
    {
        int j = i+1;
        int k = v.size()-1;

        while(j<k)
        {
            int cs=v[i];
            cs+=v[j];
            cs+=v[k];

            if(cs == sum)
            {
                ans.push_back({v[i],v[j],v[k]});
                j++;k--;
                
            }
            else if(cs > sum)
            {
                k--;
            }
            else{
                j++;
            }
        }
    }
    for(auto x:ans)
    {
        for(auto h:x)
        {
            cout<<h<<" ";
        }
        cout<<endl;
    }
}