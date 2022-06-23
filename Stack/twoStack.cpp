#include<bits/stdc++.h>
using namespace std;
class TwoStack {

public:

    // Initialize TwoStack.
	vector<int>st;
    TwoStack(int s) {
        // Write your code here.
		st.resize(s);
    }
    
    // Push in stack 1.
    void push1(int num) {
        // Write your code here.
		st.push_back(num);
    }

    // Push in stack 2.
    void push2(int num) {
        // Write your code here.
		st.push_back(num);
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
        // Write your code here.
		if(st.size()==0)
		{
			return -1;
		}
		int v = st[st.size()-1];
        st.pop_back();
        return v;
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
        // Write your code here.
        if(st.size()==0)
		{
			return -1;
		}
		int v = st[st.size()-1];
        st.pop_back();
        return v;
    }

};
