#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *l;
    Node *r;
    Node(int d)
    {
        data = d;
        l = NULL;
        r = NULL;
    }
};

Node *levelbuild()
{
    int d;
    cin >> d;
    queue<Node*>q;
    Node *root = new Node(d);

    q.push(root);

    while(!q.empty())
    {
        /* code */
        Node *f = q.front();
        q.pop();

        int c1,c2;
        cin>>c1>>c2;

        if(c1 != -1)
        {
            f->l = new Node(c1);
            q.push(f->l);
        }
        if(c2 != -1)
        {
            f->r = new Node(c2);
            q.push(f->r);
        }

    }
    return root;
}
pair<int,int>Diameter(Node *root)
{
    if(root == NULL)
    {
        return {0,0};
    }
    pair<int,int> left = Diameter(root->l);

    pair<int,int> right = Diameter(root->r);

    int h = max(left.first,right.first)+1;

    int d1 = left.first + right.first;
    int d2 = left.second; int d3 = right.second;

    int d  = max(d1,max(d2,d3));

    return {h,d};

}
int main()
{
    Node *root = levelbuild();
    pair<int,int>dia = Diameter(root);
    cout<<dia.second;
}