#include<bits/stdc++.h>
using namespace std;
template<typename t>
class Stack{

    vector<t>stack;

    public:

    void push(t data){
        stack.push_back(data);
    }

    void pop()
    {
        stack.pop_back();
    }

    t top()
    {
        return stack[stack.size()-1];
    }

    bool empty()
    {
        return stack.size()==0;
    }

};