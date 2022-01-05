#include<bits/stdc++.h>
using namespace std;
/*O(n2logn)*/
class Point{
    public:
        int x,y;
        Point(int x,int y)
        {
            this->x = x;
            this->y = y;
        }
};
class Compare{
    public:
   bool operator()(Point p1 , Point p2)
    {
        if(p1.x == p2.x)
        {
            return p1.y < p2.y;
        }
        return p1.x < p2.x;
    }
};

int pointrect(vector<Point>p)
{   int ans = 0;
    set<Point,Compare>s(p.begin(),p.end());
    for(auto i = s.begin();i!=prev(s.end());i++)
    {
            for(auto j = next(i);j!=s.end();j++)
            {
                Point p1 = *i;
                Point p2 = *j;

                if(p1.x == p2.x || p1.y == p2.y)
                {
                    continue;
                }

                Point p3(p1.x,p2.y);
                Point p4(p2.x,p1.y);    
                if(s.find(p3)!=s.end() && s.find(p4)!=s.end())
                {
                    ans++;
                }
            }
    }
    return ans/2;
}
int main()
{   vector<Point>v;
    int n;
    cin>>n;
    while(n--)
    {
        int x,y;
        cin>>x>>y;
        Point p(x,y);
        v.push_back(p);
    }
    cout<<pointrect(v);
}