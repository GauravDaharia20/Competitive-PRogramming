// find ways to place ones and zeros in an array st there is no consecutive ones
#include<bits/stdc++.h>
using namespace std;
int fun(int id,int n,bool prev){
    int ans = 0;
    if(id == n+1) return 1;

    //zero place
    ans+=fun(id+1,n,false);
    //one place
    if(prev==false){
        ans+=fun(id+1,n,true);
    }

    return ans;
}
int main(){
    for(int i=1;i<=10;i++){
        // i -> size of array
            cout<<fun(1,i,false)<<endl;
    }
    
}