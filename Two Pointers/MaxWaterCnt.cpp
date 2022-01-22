#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>dis = {2,3,4,5,18,17,6};
    int i=0; int j = dis.size()-1;
    int ans = INT_MIN;
    while (i<j)
    {
        /* code */
        int val = min(dis[i],dis[j]);
        int area = val * (j-i);
        ans = max(ans,area);

        if(dis[i] < dis[j]){
            i++;
        }
        else{
            j--;
        }
    }
    cout<<ans;
}