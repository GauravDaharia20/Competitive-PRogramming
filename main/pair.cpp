#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>v = {10,5,2,3,-6,9,11};
    int sum = 4;

    // // brute force

    // for(int i=0;i<v.size();i++)
    // {
    //     for(int j=i+1;j<v.size();j++)
    //     {
    //         if((v[i]+v[j]) == sum)
    //         {
    //             cout<<v[i]<<" "<<v[j]<<endl;
    //         }
    //     }
    // }

    // x+y = sum
    // x = sum-y -> 4-10 = -
    
    // optimized code'

    set<int>remainder;
    for(auto i:v)
    {
        int t = sum-i;
        if(remainder.find(t)!=remainder.end())
        {
            cout<<t<<" "<<i;
        }
        else{
            remainder.insert(i);
        }
    }

}