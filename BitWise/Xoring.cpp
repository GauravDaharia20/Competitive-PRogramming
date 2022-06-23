#include<bits/stdc++.h>
using namespace std;
int xoring(vector<int> v)
{
    // your code goes here
    int ans = 0;
    for(auto i:v){
        ans = ans ^ i;
    }
    return ans;

    
}
int main()
{
    cout<<xoring({1,1,2,2,4,3,3});
}