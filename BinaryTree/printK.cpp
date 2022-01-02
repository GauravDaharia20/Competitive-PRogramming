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
vector<int>ans;
void levelk(Node *root, int k)
{
    if(root==NULL || k<0)
    {
        return;
    }

    if(k==0)
    {
        ans.push_back(root->data);
        return;
    }
    levelk(root->l,k-1);
    levelk(root->r,k-1);

}
int main()
{
    Node *root = levelbuild();
    int k = 2;
    levelk(root,k);
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
}