#include <bits/stdc++.h>
using namespace std;
/*problem link :-
https://www.codingninjas.com/codestudio/problems/longest-bitonic-sequence_1062688?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
*/
int main()
{
    vector<int> arr = {1, 2, 1, 2, 1};
    int n = arr.size();

    vector<int> dp1(n, 1);
    

    for (int i = 0; i < n; i++)
    {
        // dp1[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && ((1 + dp1[j]) > dp1[i]))
            {
                dp1[i] = 1 + dp1[j];
            }
        }
    }

    vector<int> dp2(n, 1);
    
    for (int i = n - 1; i >= 0; i--)
    {
        // dp2[i] = 1;
        for (int j = n - 1; j > i; j--)
        {
            if (arr[i] > arr[j] && (1 + dp2[j]) > dp2[i])
            {
                dp2[i] = 1 + dp2[j];
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        
        ans = max(ans, dp1[i] + dp2[i] - 1);
    }
    cout << ans;
}