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
void verticalorder(Node *root,map<int,vector<int>>&ans,int d)
{
    if(root == NULL) return;
    ans[d].push_back(root->data);
    verticalorder(root->l,ans,d-1);
    verticalorder(root->r,ans,d+1);
}
int main()
{
    Node *root = levelbuild();
    map<int,vector<int>>ans;
    verticalorder(root,ans,0);
}