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

pair<bool,int>checkbalanced( Node *root)
{
    if(root == NULL)
    {
        return {true,0};
    }

    pair<bool,int>left = checkbalanced(root->l);
    pair<bool,int>right = checkbalanced(root->r);

    int h = max(left.second,right.second)+1;
    if(abs(left.second - right.second) <=1 && left.first && right.first)
    {
            return {true,h};
    }
    return {false,h};
    

}
int main()
{
    Node *root = levelbuild();
    pair<bool,int>balanced = checkbalanced(root);
    cout<<balanced.first <<" "<<balanced.second;
}