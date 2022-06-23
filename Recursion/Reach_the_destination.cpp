/*Given a source point (sx, sy) and a destination point (dx, dy), the task is to check if it is possible to reach the destination point using the following valid moves:
(a, b) -> (a + b, b)
(a, b) -> (a, a + b)
Your task is to find if it is possible to reach the destination point using only the desired moves or not.
For Example:
For the coordinates, source point = (1, 1) and destination point = (3, 5)
The output will be true as the destination point can be reached using the following sequence of moves:
(1, 1) -> (1, 2) -> (3, 2) -> (3, 5)*/

#include<bits/stdc++.h>
using namespace std;
bool check(int s1,int s2,int d1,int d2)
{
    //base case
    if(s1 > d1 || s2 > d2) return false;
    //recurence
    if(s1 == d1 && s2==d2) return true;
    return (check(s1+s2,s2,d1,d2) ^ check(s1,s2+s1,d1,d2));
}
int main()
{
    int s1,s2,d1,d2;
    cin>>s1>>s2>>d1>>d2;
    cout<<check(s1,s2,d1,d2);
}