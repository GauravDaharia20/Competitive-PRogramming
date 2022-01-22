#include <bits/stdc++.h>
using namespace std;

int main()
{   
    
    vector<int>ans;
    for(int i=0;i<length;i++)
    {
        
        if(list[i]%2==0){
            ans.push_back(list[i]);
        }
    }
    sort(ans.begin(),ans.end(),greater<int>());
    return (ans[2]);

       
}
