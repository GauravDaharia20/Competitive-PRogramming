/*You are present at point ‘A’ which is the top-left cell of an M X N matrix, your destination is point ‘B’,
 which is the bottom-right cell of the same matrix. Your task is to find the total number of unique paths from point ‘A’ to point ‘B’.
 In other words, you will be given the dimensions of the matrix as integers ‘M’ and ‘N’, your task is to find the total number of unique paths from the cell MATRIX[0][0] to MATRIX['M' - 1]['N' - 1].
To traverse in the matrix, you can either move Right or Down at each step. For example in a given point MATRIX[i] [j],
 you can move to either MATRIX[i + 1][j] or MATRIX[i][j + 1].*/

#include<bits/stdc++.h>
using namespace std;

int countWays(int m,int n,vector<vector<int>>&memo){
    if(m == 0 && n == 0) return 1;

    if( m < 0 || n < 0) return 0;

    if(memo[m][n]!=-1) return memo[m][n];
    int up = countWays(m-1,n,memo);
    int left = countWays(m,n-1,memo);
    return memo[m][n] =  up+left;
}

int main()
{
    int m,n;
    cin>>m;
    cin>>n;
    vector<vector<int>>memo(m,vector<int>(n,-1));
    cout<<"memo :"<<countWays(m-1,n-1,memo)<<endl;;

    int dp[m][n];
   // int up = 0; int left = 0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0 || j == 0){
                dp[i][j] = 1;
            }
            else{
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }
    cout<<"dp: "<<dp[m-1][n-1];
    // for(int i=0;i<m;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

}