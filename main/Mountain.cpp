#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>v = {2,1,4,7,3,2,5};
    int l=0;
    for(int i=1;i<=v.size()-2;)
    {   
        if(v[i]>v[i-1] && v[i]>v[i+1])
        {       int cnt=1;       
                int j = i;
                while (j>=1 && v[j] > v[j-1])
                { 
                      j--;
                      cnt++;
                }

                while(i<=v.size()-2 && v[i]>v[i+1])
                {
                    i++;
                    cnt++;
                }
                l = max(l,cnt);
        }
        else{
            i++;
        }
        

    }
    cout<<l;
}