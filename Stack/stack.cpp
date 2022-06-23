#include<bits/stdc++.h>
#include "stackV.h"
using namespace std;
int main()
{
    Stack<int>s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}