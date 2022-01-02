#include<bits/stdc++.h>
using namespace std;
bool check(vector<int>v,int n,int b,int sep)
{
    int loc = v[0];
    int bird = 1;
    for(int i=1;i<=n-1;i++)
    {   int curr = v[i];
        if(curr - loc >=sep)
        {
            bird++;
            loc = curr;
        }
        if(bird == b) return true;
    }
    return false;
}
int main()
{
    vector<int>v = {1,2,4,8,9};
    int b = 3;
    sort(v.begin(),v.end());
    int n = v.size();
    int s = 0; int e = v[n-1] - v[0];
    int sol = -1;
    while (s<=e)
    {
        int m = s+(e-s)/2;
        bool ans = check(v,n,b,m);
        if(ans)
        {   sol = m;
            s= m+1;
        }
        else{
            e = m-1;
        }
    }

    cout<<sol;
    

}