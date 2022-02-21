#include<bits/stdc++.h>
using namespace std;
int sum=0;
void printSubArrays(vector<int> arr, int start, int end)
{     
    
    if (end == arr.size())
        return;
       
    
    else if (start > end)
        printSubArrays(arr, 0, end + 1);
           
 
    else
    {   vector<int>ans;
       
        for (int i = start; i < end; i++){
           ans.push_back(arr[i]);
        }
         
       ans.push_back(arr[end]);
       cout<<(*min_element(ans.begin(),ans.end()));
        printSubArrays(arr, start + 1, end);
    }
     
   
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
   printSubArrays(arr, 0, 0);
    cout<<sum;
}