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
void levelprint(Node *root)
{
    queue<Node*>q;
    q.push(root);
    while (!q.empty())
    {
        /* code */
        Node *f = q.front();
        cout<<f->data<<" ";
        cout<<endl;
        q.pop();

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
int replacesum(Node *root)
{
    //base
    if(root==NULL) return 0;
    //recur

    if(root->l == NULL && root->r==NULL)
    {
        return root->data;
    }
    int ls = replacesum(root->l);
    int rs = replacesum(root->r);

    int t = root->data;
    root->data = ls+rs;
    return root->data+t;

}
int main()
{
    Node *root = levelbuild();
    replacesum(root);
    levelprint(root);

}