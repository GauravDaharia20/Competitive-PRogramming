#include <bits/stdc++.h>
using namespace std;
vector<string>ans;
set<string>st;
void permute(string s, int l, int r)
{
    if (l == r)
    {
        //cout << s << " ";
        st.insert(s);
        return;
    }

    for (int i = l; i <= r; i++)
    {
        swap(s[l], s[i]);
        permute(s, l+1, r);
        swap(s[l], s[i]);
    }
   // return;
}
int main()
{
    string s = "aabc";
    permute(s, 0, s.size() - 1);
   // sort(ans.begin(),ans.end());
    for(auto i:st) ans.push_back(i);
    for(auto i: ans) cout<<i<<" ";
    
}