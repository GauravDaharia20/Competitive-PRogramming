#include <bits/stdc++.h>
using namespace std;
vector<int> mergeK(vector<vector<int>> v)
{
    // logic
    vector<int>ans;
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;

    for(int i=0;i<v.size();i++)
    {   int element = v[i][0];
        q.push({element,i,0});
    }
    while (!q.empty())
    {
        /* code */
        auto top = q.top();
        q.pop();

        int ele = top[0];
        int aid = top[1];
        int eid = top[2];

        ans.push_back(ele);

        if(eid+1 < v[aid].size())
        {
                q.push({v[aid][eid+1],aid,eid+1});
        }

    }
    
 return ans;

}
int main()
{
    vector<vector<int>> v = {
        {10, 15, 20, 30},
        {2, 5, 8, 14, 24},
        {0, 11, 60, 90}};

    vector<int> op = mergeK(v);
    for (auto i : op)
    {
        cout << i << " ";
    }
}