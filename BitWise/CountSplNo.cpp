#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int cnt = 0;
    for(int i=1;i<=n;i++)
    {
        string nm = to_string(i);
        if(nm.size() > 1)
        {   bool f = true;
            int tc = 0;
            for(auto i:nm){
                if(((i-'0'))>=1 && ((i-'0') <=5) ){
                    f&=true;tc++;
                }
                else{
                    f&=false;tc--;
                }
            }
            if(tc == nm.size()) cnt++;
        }
        if(i>=1 && i <=5 ){
            cnt++;

        }
    }
    cout<<cnt;
}