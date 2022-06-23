#include <bits/stdc++.h>
using namespace std;
class Stack
{

    queue<int> q1, q2;

public:
    bool empty()
    {
        return q1.empty() && q2.empty();
    }
    void push(int d)
    {
        if (q1.empty())
        {
            q1.push(d);
        }
        else
        {
            q2.push(d);
        }
    }

    void pop()
    {
        if (q1.empty())
        {
            while (!q2.empty())
            {
                /* code */
                int f = (q2.front());
                q2.pop();

                if (q2.empty())
                {
                    break;
                }

                q1.push(f);
            }
        }
        else
        {

            while (!q1.empty())
            {
                /* code */
                int f = (q1.front());
                q1.pop();

                if (q1.empty())
                {
                    break;
                }

                q2.push(f);
            }
        }   
    }

    int top()
    {
        if (q1.empty())
        {
            while (!q2.empty())
            {
                /* code */
                int f = (q2.front());
                q2.pop();
                q1.push(f);
                if (q2.empty())
                {
                    return f;
                }

            }
        }
        else
        {

            while (!q1.empty())
            {
                /* code */
                int f = (q1.front());
                q2.push(f); 
                q1.pop();
                if (q1.empty())
                {
                    return f;
                }
                
            }
        }
    }
};
    int main()
    {
        Stack s;
        s.push(1);
        s.push(2);

        
        s.push(1);
        s.push(2);

        while(!s.empty()){
            cout<<s.top();
            s.pop();
        }
        
    }