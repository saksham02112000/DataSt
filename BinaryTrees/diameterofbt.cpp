#include<bits/stdc++.h>
using namespace std;
// #define max(a,b) (a>b:a?b)
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

int calcheight(Node* root)
{
    if (root== NULL)
    {
        return 0;
    }
    return max(calcheight(root->left), calcheight(root->right));
}

int calcdia(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int lheight=calcheight(root->left);
    int rheight=calcheight(root->right);
    int currdia=lheight+rheight+1;

    int lDia=calcdia(root->left);
    int rDia=calcdia(root->right);
    return max(currdia,max(lDia,rDia));
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
    cout<<calcdia(root);
    return 0;
}