#include<bits/stdc++.h>
using namespace std;
class Cab{
    public:
    string d;
    int x; int y;

    Cab(string d, int x,int y)
    {
        this->d = d;
        this->x = x;
        this->y = y;

    }
    int dis() const{
        return x*x - y*y;
    }
};

class Comp
{
    public:
        bool operator()(Cab a, Cab b)
        {
            return a.dis() < b.dis();
        }

};
void printnearcar(vector<Cab>cars,int k)
{
    priority_queue<int,vector<Cab>, Comp>pq(cars.begin(),cars.begin()+k);

    for (int i = k; i < cars.size(); i++)
    {
        auto car = cars[i];
        if(car.dis() < pq.top().dis())
        {
            pq.pop();
            pq.push(car);
        }
    }
    while (!pq.empty())
    {
        /* code */
        cout<<pq.top().d<<" ";
        pq.pop();
    }
    
}
int main()
{
    int n,k;
    cin>>n>>k;
    string id;
    int x,y;

    vector<Cab>cars;

    for(int i=0;i<n;i++)
    {
        cin>>id>>x>>y;
        Cab cab(id,x,y);
        cars.push_back(cab);
    }

    printnearcar(cars,k);

}