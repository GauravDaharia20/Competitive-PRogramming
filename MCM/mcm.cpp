#include <bits/stdc++.h>
using namespace std;
/*
    logic => we will find value of k lying between i and j

    steps to find answer:

    1. i,j ki position
    2. funtion call => [func(i,k) + func(k+1,j)] => jb aap k=i se chalu kare
            or
        [func(i,k-1) + func(k,j-1)]  => jb aap k=i+1 , k=j

*/
int solve(vector<int> &v, int i, int j)
{   /*
        ager sirf ek hi cell bach ra hai then value will be zero
    */
    if( i>=j){
        return 0;
    }
    int min_ans = INT_MAX;

    for(int k = i;k<=j-1;k++){
        int ans = solve(v,i,k) + solve(v,k+1,j) + (v[i-1] * v[k] * v[j]);
       // cout<<i<<" "<<j<<" "<<k<<" "<<solve(v,i,k)<<" "<<solve(v,k+1,j)<<" "<<(v[i-1] * v[k] * v[j])<<endl;
        min_ans = min(min_ans , ans);
    }

    return min_ans;
}
int main()
{
    vector<int> v = {40, 20, 30, 10, 30};

    cout << solve(v, 1, v.size() - 1);
}