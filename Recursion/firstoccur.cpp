#include <bits/stdc++.h>
using namespace std;
int findelement(int *a, int k, int n)
{

    if (n == 0)
    {
        return -1;
    }

    if (a[0] == k)
    {
        return 0;
    }
    int sb = findelement(a + 1, k, n - 1);
    if (sb != -1)
        return sb + 1;
    return -1;
}

vector<int>ans;
void  alloccurence(int a[],int id,int n,int k)
{
    //base case

    if(id == n-1) return ;

    if(a[id] == k){
        ans.push_back(id);
    }
    alloccurence(a,id+1,n,k);
}



int lastOccurence(int a[], int n, int k)
{   //base
    if (n == 0)
        return -1;

    int si = lastOccurence(a + 1, n - 1, k);
    if (si == -1)
    {
        if (a[0] == k)
        {
            return 0;
        }
        else{
            return -1;
        }
    }
    else if (si != -1)
    {
        return si + 1;
    }
    return -1;
}

int main()
{
    int n, k;
    cin >> n >> k;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    //cout<<findelement(a,k,n);
    alloccurence(a,0, n, k);
    for(auto i : ans) cout<<i<<" ";
}