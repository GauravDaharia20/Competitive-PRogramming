#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    deque<int> q;
    // deque<int> q(k);
    // int i;
    // for (i = 0; i < k; i++)
    // { // dicard those element which is less than curret element;
    //     while (!q.empty() && v[i] > v[q.back()])
    //     {
    //         q.pop_back();
    //     }
    //     q.push_back(i);
    // }
    // for (; i < v.size(); i++)
    // {
    //     cout << v[q.front()] << " ";
    //     while (!q.empty() && q.front() <= i - k)
    //     {
    //         q.pop_front();
    //     }
    //     while (!q.empty() && v[i] > v[q.back()])
    //     {
    //         q.pop_back();
    //     }

    //     q.push_back(i);
    // }

    for(int i=0;i<v.size();i++)
    {
            if(!q.empty() && q.front() <= i-k)  // out of window
            {
                q.pop_front();
            }
            while(!q.empty() && v[i] > v[q.back()]) 
            {
                q.pop_back();
            }
            q.push_back(i);

            if( i >=k-1)
            {
                cout<<v[q.front()]<<" ";
            }
    }
}