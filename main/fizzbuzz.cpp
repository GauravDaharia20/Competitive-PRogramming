#include<bits/stdc++.h>
using namespace std;
int main()
{   vector<string>ans;
    int n;
    cin>>n;
    vector<string>ans;
    for(int i=1;i<=n;i++)
    {
        if(i%15 == 0)
        {
            ans.push_back("FizzBuzz");
        }
        else if(i%5 == 0)
        {
            ans.push_back("Buzz");
        }
        else if(i%3==0)
        {
            ans.push_back("Fizz");
        }
        else{
            ans.push_back(to_string(i));
        }
    }

    for(auto i:ans) cout<<i<<" ";
}