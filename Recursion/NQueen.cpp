#include<bits/stdc++.h>
using namespace std;
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
bool canPlace(int n,int board[][20],int x,int y){

    //cols
    for(int k = 0;k<x;k++)
    {
        if (board[k][y]==1) 
        {
            return false;
        }
    }

    int i = x; int j = y;
    //left dag
    while(i >= 0 && j >= 0)
    {
        if(board[i][j]==1) {
            return false;
        }

        i--;
        j--;
    }
    i=x;
    j=y;
    while(i >=0 && j<n)
    {
        if(board[i][j]==1) {
            return false;
        }
        i--;
        j++;
    }

    return true;

}
bool solveQueen(int n,int board[][20],int i)
{
    if(i == n)
    {
        printBoard(n,board);
        return true;
    }

    for(int j=0;j<n;j++)
    {
        if(canPlace(n,board,i,j)){
            board[i][j] = 1;
            bool success = solveQueen(n,board,i+1);

            if(success){
                return true;
            }
            //backtrack
            board[i][j] = 0;
        }
    }

    return false;
}
int main()
{
    int board[20][20]={0};
    int n;
    cin>>n;
    solveQueen(n,board,0);
}