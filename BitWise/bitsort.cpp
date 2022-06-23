#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
int comp(int a, int b)
{
    return __builtin_popcount(a) > __builtin_popcount(b);
    return (__builtin_popcount(a) == __builtin_popcount(b));
    
}
void sortSetBitsCount(vector<int> &arr, int size)
{
    // Write your code here
    sort(arr.begin(), arr.end(), comp);
    for (auto i : arr)
    {
        cout << i << " ";
    }
}
int main()
{
    vector<int> v = {4,3,8};
    sortSetBitsCount(v, v.size());
}