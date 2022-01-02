#include <bits/stdc++.h>
using namespace std;
bool check(string s)
{
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != ')')
        {
            st.push(s[i]);
        }
        else
        {
            bool f = false;
            while (!st.empty() && st.top() != '(')
            {
                char t = st.top();
                if (t == '+' || t == '-' || t == '*' || t == '/')
                {
                    f = true;
                }
                st.pop();
            }
            st.pop();

            if (f == false)
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    string s = "((a+b))";

    cout << check(s);
}