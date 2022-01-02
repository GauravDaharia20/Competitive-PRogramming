#include<bits/stdc++.h>
using namespace std;
bool check(vector<int> &arr)
{
    bool f = true;
    for(auto i:arr)
    {
       if(i<0)
       {
           f = true;
       }
    }
    return f;
}
int main()
{
    vector<int>arr = {-1,-2,-3};
      int n = arr.size();
    int cs = 0;
    int ms = 0;
    
    for(int i=0;i<n;i++){
        cs += arr[i];
        ms = max(ms,cs);
        if(cs<0){
            cs = 0;
        }
    }
    cout<< ms;
}