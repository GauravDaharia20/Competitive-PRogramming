#include<bits/stdc++.h>
using namespace std;
void permutation(string s, int i, int n)
{
    if(i == n){
        cout<<s<<" ";
        return;
        
    }
    for(int st = i;st<=n;st++)
    {
        swap(s[i],s[st]);
        permutation(s,i+1,n);
        swap(s[i],s[st]);
    }
    
}
int main()
{
    string s;
    cin>>s;
    permutation(s,0,s.size()-1);
}