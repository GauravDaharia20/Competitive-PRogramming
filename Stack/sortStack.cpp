/*You’re given a stack consisting of 'N' integers. Your task is to sort this stack in descending order using recursion.
We can only use the following functions on this stack S.
is_empty(S) : Tests whether stack is empty or not.
push(S) : Adds a new element to the stack.
pop(S) : Removes top element from the stack.
top(S) : Returns value of the top element. Note that this function does not remove elements from the stack.
Note :
1) Use of any loop constructs like while, for..etc is not allowed. 
2) The stack may contain duplicate integers.
3) The stack may contain any integer i.e it may either be negative, positive or zero.*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    priority_queue<int>p;
    stack<int>s;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        s.push(v[i]);
    }
    while(!s.empty())
    {
        p.push(s.top());
        s.pop();
    }
    while(!p.empty()){
        cout<<p.top()<<" ";
        p.pop();
    }

}