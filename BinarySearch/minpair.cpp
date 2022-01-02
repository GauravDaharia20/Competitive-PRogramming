#include<bits/stdc++.h>
using namespace std;
void mins_pair(vector<int>a1,vector<int>a2)
{
    int p1,p2;int diff = INT_MAX;
    sort(a2.begin(),a2.end());
    for(int i:a1)
    {
        auto lb = lower_bound(a2.begin(),a2.end(),i)-a2.begin();
        //left
        if(lb >=1 && i-a2[lb-1] < diff)
        {
            diff = i-a2[lb-1];
            p1 = i;
            p2 = a2[lb-1];
        }
        //right
        if(lb!=a2.size() && a2[lb]-i < diff)
        {
            diff = a2[lb]-i;
            p1 = a2[lb];
            p2 = i;
        }
    }
    cout<<p1<<" "<<p2;

}
int main()
{
    vector<int>a1 = {-1,5,10,20,3};
    vector<int>a2 = {26,134,135,15,17};
    mins_pair(a1,a2);
}