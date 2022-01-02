#include<bits/stdc++.h>
using namespace std;
vector<string>key = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
void keypad(string n,string output,int i)
{
    if(n[i]=='\0')
    {
        cout<<output<<endl;
        return;
    }
    int cn = n[i]-'0'; 
    if(cn ==0 || cn==1)
    {
        keypad(n,output,i+1);
    }

    for(int j=0;j<key[cn].size();j++)
    {
        keypad(n,output+key[cn][j],i+1);
        
    }
    return;
}
int main()
{
    string n;
    cin>>n;
    keypad(n,"",0);
}