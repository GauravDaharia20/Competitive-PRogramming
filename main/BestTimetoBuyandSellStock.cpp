#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
   int minmal = INT_MAX;
   int profit = 0;
   for(int i=0;i<v.size();i++)
   {
       if(v[i] < minmal){
           minmal = v[i];
          
       }
       if(v[i] - minmal > profit){
           
           profit = v[i] - minmal;
       }
   }     
   cout<<profit;
}