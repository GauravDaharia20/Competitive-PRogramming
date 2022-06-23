#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v = {5, -3, 2, 3, -4};
    int k = 2;
    deque<int> dq;
    int i;
    for (i = 0; i < k; i++)
    {
        if (v[i] < 0)
        {
            dq.push_back(i);
        }
    }
    for (; i < v.size(); i++)
    {
        if (!dq.empty())
        {
            cout << v[dq.front()] << " ";
        }
        else{
            cout<<0<<" ";
        }
        while((!dq.empty()) && dq.front() < (i-k+1)){
            dq.pop_front();
        }
        if(v[i]<0) dq.push_back(i);
        
    }
    if (!dq.empty())
        {
            cout << v[dq.front()] << " ";
        }
        else{
            cout<<0<<" ";
        }

}