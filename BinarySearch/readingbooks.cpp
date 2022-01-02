#include <bits/stdc++.h>
using namespace std;
bool check(vector<int> v, int p, int r)
{
    int student = 1;
    int curr_sum = 0;

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] > r)
        {
            return false;
        }

        if (curr_sum + v[i] > r)
        {
            student++;
            curr_sum = v[i];
            if (student > p)
            {
                return false;
            }
        }
        else{
            curr_sum+=v[i];
        }
    }
    return true;
}
int findbooks(vector<int> v, int p)
{
    int n = v.size();
    if (n < p)
    {
        return -1;
    }
    int sol = -1;
    int s = 0;
    int e = accumulate(v.begin(), v.end(), 0);
    while (s <= e)
    {
        int m = s + (e - s) / 2;
        bool ans = check(v, p, m);
        if (ans)
        {
            sol = m;
            cout<<sol<<endl;
            e = m - 1;
        }
        else
        {
            s = m + 1;
        }
    }
    return sol;
}
int main()
{
    vector<int> v = {10, 20, 30, 15};
    cout << findbooks(v, 2);
}