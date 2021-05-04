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

int search(int inorder[], int start, int end , int curr)
{
    for (int i = start; i <= end; i++)
    {
        if(inorder[i]==curr)
        {
            return i;
        }
    }
    return -1;
}

Node* buildtree(int preorder[], int inorder[], int start, int end)
{
    if (start>end)
    {
        return NULL;
    }
    static int ind=0;
    int curr=preorder[ind];
    ind++;
    Node* node=new Node(curr);
    if(start==end)
    {
        return node;
    }
    int pos=search(inorder, start, end, curr);
    node->left=buildtree(preorder,inorder, start, pos-1);
    node->right=buildtree(preorder,inorder, pos+1, end);
}

void inorderpr(Node* root)
{
    inorderpr(root->left);
    cout<< root->data<<" ";
    inorderpr(root->right);

}

int main()
{
    int preorder[]={1,2,4,3,5};
    int inorder[]={4,2,1,5,3};

    Node* root=buildtree(preorder,inorder,0,4);
    inorderpr(root);
    return 0;
}