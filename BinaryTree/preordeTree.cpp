#include <bits/stdc++.h>
using namespace std;
// 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

vector<int> printKthLevel(Node* root, int k){

    if(root==NULL) return {};

    int level = 0;
    int flag = false;
    queue<Node*>q;
    set<int>s;
    q.push(root);

    while (!q.empty())
    {
        /* code */
        int n = q.size();
        while (n--)
        {
            /* code */
            Node *f = q.front();
            q.pop();

            if(level == k)
            {
                flag=true;
                s.insert(f->data);
            }
            else{
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
            }
        }
        level++;

        if(flag==true) break;
        
    }
    
    vector<int>v(s.begin(),s.end());
    return v;

}



void preorder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
Node *BuildTree()
{
    int d;
    cin >> d;
    if (d == -1)
    {
        return NULL;
    }
    Node *root = new Node(d);
    root->left = BuildTree();
    root->right = BuildTree();

    return root;
}

void levelOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        /* code */
        Node *f = q.front();
        if (f == NULL)
        {
            cout << endl;
            q.pop();
            if (!q.empty())
                q.push(NULL);
        }
        else
        {   q.pop();
            cout<<f->data<<" ";
            if (f->left)
            {
                q.push(f->left);
            }
            if (f->right)
            {
                q.push(f->right);
            }
        }
    }
    return;
}

Node *levelOrdeBuild()
{
    int d;
    cin>>d;
    Node *root = new Node(d);

    queue<Node*>q;
    q.push(root);

    while (!q.empty())
    {
        /* code */
        Node *f = q.front();
        q.pop();

        int c1,c2;
        cin>>c1>>c2;

        if(c1!=-1)
        {
            f->left = new Node(c1);
            q.push(f->left);
        }
        if(c2!=-1)
        {
            f->right = new Node(c2);
            q.push(f->right);
        }

    }
    return root;
}

int main()
{
    Node *root = levelOrdeBuild();
    //levelOrder(root);
    vector<int>ans = printKthLevel(root,2);
    for(auto i:ans) cout<<i<<" ";
}