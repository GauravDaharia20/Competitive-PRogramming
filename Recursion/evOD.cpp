#include<bits/stdc++.h>
using namespace std;
bool findTriplet(vector<int>& arr)
{
    int n = arr.size();
    stack<int> st;
 
    // Initialize the heights of h1 and h2
    // to INT_MAX and INT_MIN respectively
    int h3 = INT_MIN, h1 = INT_MAX;
    for (int i = n - 1; i >= 0; i--) {
 
        // Store the current element as h1
        h1 = arr[i];
 
        // If the element at top of stack
        // is less than the current element
        // then pop the stack top
        // and keep updating the value of h3
        while (!st.empty()
            && st.top() < arr[i]) {
 
            h3 = st.top();
            st.pop();
        }
 
        // Push the current element
        // on the stack
        st.push(arr[i]);
 
        // If current element is less
        // than h3, then we found such
        // triplet and return true
        if (h1 < h3) {
            return true;
        }
    }
 
    // No triplet found, hence return false
    return false;
}
int main()
{
    vector<int>v = {3,2,1};
    cout<<!(findTriplet(v));
}