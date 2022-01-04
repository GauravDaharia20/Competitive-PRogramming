#include<bits/stdc++.h>
using namespace std;
int searchbin(vector<int>v,int k)
{
    int s = 0; int e = v.size()-1;
    while (s<=e)
    {
        /* code */
        int m = s+(e-s)/2;

        if(v[m] == k)
        {
            return v[m];
        }
        if(v[m] > k)
        {
                e = m-1;
        }
        else{
            s = m+1;
        }
    }
    return min(abs(v[e]-k), abs(v[s]-k));
}

// int searchflore(vector<int>v,int k)
// {   int ans = -1;
//     int s = 0; int e = v.size()-1;
//     while (s<=e)
//     {
//         /* code */
//         int m = s+(e-s)/2;
//         if(v[m] == k)
//         {
//             return v[m];
//         }
//         if(v[m] < k)
//         {
//                 ans = v[m];
//                 s = m+1;
//         }
//         else{
//             e = m-1;
//         }
//     }
//     return ans;
    
// }


// int searchceil(vector<int>v,int k)
// {   int ans = -1;
//     int s = 0; int e = v.size()-1;
//     while (s<=e)
//     {
//         /* code */
//         int m = s+(e-s)/2;
//         if(v[m] == k)
//         {
//             return v[m];
//         }
//         if(v[m] > k)
//         {
//             ans = v[m];
//             e = m-1;
//         }
//         else{
//             s = m+1;
//         }
//     }
//     return ans;
    
// }

int main()
{
    vector<int>v = {1,3,8,10,15};
    int ans1 = searchbin(v,12);
    // int ans2 = searchflore(v,12);
    // int ans3 = searchceil(v,12);

    cout<<ans1 ;

}