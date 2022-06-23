#include<bits/stdc++.h>
using namespace std;
/*Reverse a given stack of integers using recursion.*/
void insert(stack<int> &st , int t)
{
    if(st.size() == 0){
        st.push(t); return;
    }

    int tp = st.top();
  
    st.pop();
    insert(st,t);
    st.push(tp);
    return;

}
void reverseStack(stack<int> &st) {
    // Write your code here

    if(st.empty()) return;

    int t = st.top();
   // cout<<t<<" ";
    st.pop();
    reverseStack(st);
    insert(st,t);
    

    
}
int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    stack<int>st;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    for(auto i:v){
        st.push(i);
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }


}