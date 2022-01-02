#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v = {1, 9, 3, 0, 18, 5, 2, 4, 10, 7, 12, 6};

    int l = 1;
    set<int> t(v.begin(), v.end());
    for (auto i : v)
    {
        int p = i - 1;
        if (t.find(p) == t.end())
        {
            int cnt = 1;
            int nn = i+1;
            while (t.find(nn) != t.end())
            {
                nn++;
                cnt++;
            }
            l = max(l, cnt);
        }
    }
    cout << l;
}