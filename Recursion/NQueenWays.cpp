#include<bits/stdc++.h>
using namespace std;
bool canPlace(int n,int board[][20],int x,int y)
{
    for(int k=0;k<x;k++)
    {
        if(board[k][y] == 1) return false;
    }
    int i=x;int j=y;
    //left
    while(i>=0 && j>=0)
    {
        if(board[i][j] == 1) return false;
        i--;
        j--;
    }

    //right

    i=x;j=y;
    while(i>=0 && j < n)
    {
        if(board[i][j] == 1 ) return false;
        i--;
        j++;
    }

    return true;

}
void printBoard(int n,int board[][20])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
int solveQueen(int n,int board[][20],int i)
{
    if( i == n)
    {
        printBoard(n,board);
        return 1;
    } 

    int ways = 0;

    for(int j=0;j<n;j++)
    {
        if(canPlace(n,board,i,j)){
            board[i][j] = 1;
            ways+=solveQueen(n,board,i+1);
        }
        board[i][j]=0; // backtrack
    }

    return ways;

}
int main()
{
    int n;
    cin>>n;
    int board[20][20]={0};
    solveQueen(n,board,0);
}