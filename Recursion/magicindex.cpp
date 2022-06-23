/*You are given a sorted array A consisting of N integers. Your task is to find the magic index in the given array.
Note :
A magic index in an array A[0 ... N - 1] is defined to be an index i such that A[i] = i.

The elements in the array can be negative.

The elements in the array can be repeated multiple times.

There can be more than one magic index in an array.*/

#include<bits/stdc++.h>
using namespace std;
int help(vector<int>v, int i, int n)
{
    if(i == n) return -1;

    if(v[i] == i)
    {
        return v[i];
    }
    return help(v,i+1,n);
}
int magicIndex(vector<int> v, int n) {
	// Write your code here
    return help(v,0,n);
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }

    cout << magicIndex(v,v.size());

}