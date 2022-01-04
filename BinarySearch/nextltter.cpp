#include<bits/stdc++.h>
using namespace std;
char binsearh(vector<char>v,char k)
{
    char ans = '\0';
    int s=0; int e = v.size()-1;
    while (s<=e)
    {
        /* code */
        int m = s+(e-s)/2;
        if(v[m] == k)
        {
            s = m+1;

        }
        if(v[m] > k)
        {
            ans = v[m];
            e = m-1;
        }
        else{
           
            s= m+1;
        }

    }
    return ans;

}
int main()
{
    vector<char>v = {'a','c','f','h'};
    cout<<binsearh(v,'f');
}