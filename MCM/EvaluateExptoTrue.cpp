#include <bits/stdc++.h>
using namespace std;
/*
    logic:
        we need to make expression true with cuts
        1. i->i+1, j=len(exp)-1
        2. func(i,k-1) , func(k+1,j)
        3. it is totally boolean exp

*/
int EvalExp(string exp, int i, int j, bool flg)
{

    if (i > j)
        return 0;

    if (i == j)
    {
        if (flg == true)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int ans = 0;
    for (int k = i + 1; k <= j - 1; k = k + 2)
    {
        int lt = EvalExp(exp, i, k - 1, true);
        int lf = EvalExp(exp, i, k - 1, false);

        int rt = EvalExp(exp, k + 1, j, true);
        int rf = EvalExp(exp, k + 1, j, false);

        if (exp[k] == '&')
        {
            if (flg == true)
            {
                ans += (lt * rt);
            }
            else
            {
                ans += (lf * rt + rf * lt + lf * rf);
            }
        }
        else if (exp[k] == '|')
        {
            if (flg == true)
            {
                ans += (lt * rt + lf * rt + lt * rf);
            }
            else
            {
                ans += (lf * rf);
            }
        }
        else if (exp[k] == '^')
        {
            if (flg == true)
            {
                ans += (lt * rf + rt * lf);
            }
            else
            {
                ans += (lt * rt + rf * lf);
            }
        }
    }

    return ans;
}
int main()
{
    string exp = "T^F&T";
    cout << EvalExp(exp, 0, exp.size() - 1, false);
}