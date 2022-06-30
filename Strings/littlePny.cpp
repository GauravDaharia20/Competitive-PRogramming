#include<bits/stdc++.h>
using namespace std;
// int help(vector<int> &A , int val){
//     int cnt = 0;
//     int sum = 0;
//     for(auto i:A){
//         sum+=i;
//         if(sum < val){
//             cnt++;
//         }else if(sum > val){
//             break;
//         }
//     }
//     return cnt;
// }
vector<int> solve(vector<int> &A, vector<int> &B) {

    int n = A.size();
    for(int i=1;i<=n;i++){
        A[i] = A[i] + A[i-1];
    }
    vector<int>ans;
    for(int i=0;i<B.size();i++){
        for(int j=0;j<A.size();j++){
            if(A[j] < B[i]){
                ans.push_back(i+1);
            }
            else{
                ans.push_back(0);
            }
        }
    }
    return ans;

}
int main()
{
    vector<int>A = {3,4,4,6};
    vector<int>B = {20,4,10,2};

    vector<int> ans = solve(A,B);
    for(auto i:ans) cout<<i<<" ";

    // int n = A.size();
    // for(int i=1;i<=n;i++){
    //     A[i] = A[i] + A[i-1];
    // }
    //for(auto i:A) cout<<i<<" ";

}