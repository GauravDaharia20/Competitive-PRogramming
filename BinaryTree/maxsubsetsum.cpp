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
//O(n)
pair<int,int>subsetsum(Node *root)
{
    if(root==NULL)
    {
        return {0,0};
    }
    pair<int,int>left = subsetsum(root->l);
    pair<int,int>right = subsetsum(root->r);
    int inc = root->data + left.second + right.second;

    int exe = max(left.first,left.second) + max(right.first,right.second);
    return {inc,exe};
}
int main()
{
    Node *root = levelbuild();
    pair<int,int>ans = subsetsum(root);
    cout<<ans.first << " "<<ans.second;
}