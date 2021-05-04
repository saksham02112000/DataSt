#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};

int countallnodes(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    return countallnodes(root->left)+countallnodes(root->right)+1;
}

int sumofallnodes(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int sl=sumofallnodes(root->left);
    int sr=sumofallnodes(root->right);
    return sl+sr+root->data;
}

int main()
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    cout<<countallnodes(root)<<endl;
    cout<<sumofallnodes(root);
    return 0;
}