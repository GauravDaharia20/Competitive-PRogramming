#include <bits/stdc++.h>
using namespace std;
int findPeak(vector<int> v, int s, int e)
{
    int m = s + (e - s) / 2;
    if ((m == 0 || v[m - 1] <= v[m]) && (m == v.size() - 1 || v[m] >= v[m + 1]))
    {
        return m;
    }
    else if (v[m - 1] > v[m])
    {
        return findPeak(v, s, m - 1);
    }
    else
    {
        return findPeak(v, m + 1, e);
    }
}
int findelement(vector<int> v, int s, int e, int k)
{
    int st = s;
    int et = e;

    while (st <= et)
    {
        /* code */
        int m = st + (et - st) / 2;
        if (v[m] == k)
        {
            return m;
        }
        if (v[m] > k)
        {
            et = m-1;
        }
        else
        {
          st = m+1;
        }
    }

    return -1;
}

int findelements(vector<int> v, int s, int e, int k)
{
    int st = s;
    int et = e;

    while (st <= et)
    {
        /* code */
        int m = st + (et - st) / 2;
        if (v[m] == k)
        {
            return m;
        }
        if (v[m] > k)
        {
            st = m+1;
        }
        else
        {
          et = m-1;
        }
    }

    return -1;
}
int main()
{
    vector<int> v = {1, 3, 8, 12, 4, 2};
    int k = 1;
    int pid = findPeak(v, 0, v.size() - 1);
    //cout<<pid;
    int ans1 = findelement(v, 0, pid - 1, k);
     int ans2 = findelements(v,pid + 1,v.size()-1,k);
     cout << ans1<<" "<<ans2;
}