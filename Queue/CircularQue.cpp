#include<bits/stdc++.h>
using namespace std;
class CircularQue
{
private:
    int cs, ms, fr, rr;
    int *arr;

public:
    CircularQue(int default_size = 5)
    {
        ms = default_size;
        cs = 0;
        fr = 0;
        rr = ms - 1;
        arr = new int[ms];
    }

    bool full()
    {
        return cs == ms;
    }

    bool empty(){
        return cs==0;
    }
    void push(int d)
    {
        if (!full())
        {

            rr = (rr + 1) % ms;
            arr[rr] = d;
            cs++;
        }
    }

    void pop(){
        if(!empty()){
            fr = (fr+1)%ms;
            cs--;
        }
    }
    int front(){
        return arr[fr];
    }
};
int main()
{
    CircularQue mq(6);
    mq.push(1);
    mq.push(2);
    mq.push(3);
    mq.push(4);
    mq.push(5);
    mq.push(6);
    mq.pop();

    while (!mq.empty())
    {
        /* code */
        cout<<mq.front()<<" ";
        mq.pop();

    }
    
}