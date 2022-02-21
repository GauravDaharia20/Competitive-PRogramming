#include<bits/stdc++.h>
using namespace std;
int main()
{
    union u{
        int x;
        char *a;
    };
    union u i;
    i.x = 20;
    cout<<i.a<<i.x;

}