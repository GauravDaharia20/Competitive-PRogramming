#include<bits/stdc++.h>
using namespace std;
bool dfs(vector<vector<char>>&maze,vector<vector<int>>&sol,int i,int j,int n,int m,vector<vector<int>>&res){

    if(i < 0 || j < 0 || i >=n || j >=m || maze[i][j]=='x' || sol[i][j]==1){
        return false;
    }
    if(i==n-1 && j==m-1 && maze[i][j]=='o'){
        vector<int>p;
        sol[i][j] = 1;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                p.push_back(sol[i][j]);
            }
        }
        res.push_back(p);

    }
    sol[i][j]=1;
    dfs(maze,sol,i+1,j,n,m,res);
    dfs(maze,sol,i-1,j,n,m,res);
    dfs(maze,sol,i,j+1,n,m,res);
    dfs(maze,sol,i,j-1,n,m,res);

    sol[i][j]=0;

    
}
int main()
{
    int n,m;
    cin>>n>>m;

        // {'o','x','o','o'},
        // {'o','o','o','x'},
        // {'x','o','x','o'},
        // {'x','o','o','x'},
        // {'x','x','o','o'},

        vector<vector<char>>maze(n,vector<char>(m));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>maze[i][j];
            }
        }


        vector<vector<int>>sol(n,vector<int>(m,0));
        vector<vector<int>>res;
        dfs(maze,sol,0,0,n,m,res);
        cout<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }

        
        
    
    



    

    
}