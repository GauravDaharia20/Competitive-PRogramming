#include<bits/stdc++.h>
using namespace std;
/*
    concept -> Either add element to knapsack or not add.
*/

int Knapsack(vector<int>wt,vector<int>val,int W,int n){
    //base case

    if(n == 0 || W==0)
    {
        return 0;
    }

    if(wt[n-1] <=W)
    {
        int inc = val[n-1] + Knapsack(wt,val,W-wt[n-1],n-1);
        cout<<"inc"<<inc<<endl;
        int exc = Knapsack(wt,val,W,n-1);
        cout<<"exc"<<exc<<endl;
        return max(inc,exc);
    }
    else{
        return Knapsack(wt,val,W,n-1);
    }
}
int main()
{
    vector<int>val = {2,5,6,3};
    vector<int>wt = {1,4,5,2};
    int W = 10;
    cout<<Knapsack(wt,val,W,val.size());
}