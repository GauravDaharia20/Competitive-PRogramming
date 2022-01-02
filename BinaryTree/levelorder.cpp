#include <bits/stdc++.h>
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

Node *build()
{
    int d;
    cin >> d;

    if (d == -1)
    {
        return NULL;
    }
    Node *n = new Node(d);

    n->l = build();
    n->r = build();

    return n;
}
void levelorder(Node *root)
{
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        Node *f = q.front();
        cout<<f->data<<" ";
        q.pop();
        cout<<endl;
        if(f->l)
        {
            q.push(f->l);
        }
        if(f->r)
        {
            q.push(f->r);
        }
    }
}
int main()
{
    Node *root = build();
    levelorder(root);
}