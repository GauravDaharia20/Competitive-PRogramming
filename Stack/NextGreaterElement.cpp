#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>v = {1, 6, 4, 3, 5};
    // O(n2)
    // for(int i=0;i<v.size();i++)
    // {
    //     int nxt = -1;
    //     for(int j=i+1;j<v.size();j++)
    //     {
    //         if(v[j] > v[i]){
    //             nxt = v[j];
    //             break;
    //         }
    //     }
    //     cout<<nxt<<" ";
    // }

    stack<int>st;
    vector<int>rs(v.size(),-1);
    for(int i=0;i<v.size();i++)
    {
        while(!st.empty() && v[st.top()] < v[i]){
            rs[st.top()]=(v[i]);
            st.pop();
        }
        st.push(i);
    }

    for(auto i:rs){
        cout<<i<<" ";
    }


}
