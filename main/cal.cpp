#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        /* code */
        int n;
        cin >> n;
        vector<int> v(n);
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        //ans.push_back(v[0]);

        for (int i = 1; i < n; i++)
        {
            int a = v[i] & v[i - 1];
            ans.push_back(a);
        }
        int ans1 = 0;
        for (auto i : ans)
        {
            ans1 = ans1 | i;
        }
        cout <<ans1<<endl;;
    }
}
