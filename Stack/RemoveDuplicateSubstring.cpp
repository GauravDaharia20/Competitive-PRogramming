#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s = "abcbacaacd";
    int k = 2;
    deque<char>d;
    for(int i=0;i<s.size();i++)
    {

        
        if(d.back()==s[i] && k!=0){ 
            d.pop_back();
            k--;
        }
        else{
            d.push_back(s[i]);
        }  
    }
    while(!d.empty()){
        cout<<d.front();
        d.pop_front();
    }    
        
    
    
}