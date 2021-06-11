#include <bits/stdc++.h>
using namespace std;

//building segment tree
void buildtree(int *arr, int *tree, int start, int end, int index)
{
    if (start == end)
    {
        tree[index] = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    buildtree(arr, tree, start, mid, 2 * index);
    buildtree(arr, tree, mid + 1, end, 2 * index + 1);
    tree[index] = tree[index * 2] + tree[index * 2 + 1];
}

//update segment tree
void updatetree(int *arr, int *tree, int start, int end, int treenode, int upind, int value)
{
    if (start == end)
    {
        arr[upind] = value;
        tree[treenode] = value;
        return;
    }
    int mid = (start + end) / 2;
    if (upind > mid)
        updatetree(arr, tree, mid + 1, end, 2 * treenode + 1, upind, value);
    else
        updatetree(arr, tree, start, mid, treenode * 2, upind, value);
    tree[treenode] = tree[2 * treenode] + tree[2 * treenode + 1];
}

//query from segment tree
int query(int *tree, int start, int end, int treenode, int startrange, int endrange)
{
    //out of range
    if (start > endrange || end < startrange)
    {
        return 0;
    }
    //in range
    if (start >= startrange && end <= endrange)
    {
        return tree[treenode];
    }
    //else cases
    int mid = (start + end) / 2;
    int option1 = query(tree, start, mid, treenode * 2, startrange, endrange);
    int option2 = query(tree, mid + 1, end, treenode * 2 + 1, startrange, endrange);
    return option1 + option2;
}

//lazy propagation
void lazyf(int *tree, int *lazy, int start, int end, int startR, int endR, int currPos, int inc)
{
    if (start > end)
    {
        return;
    }
    if (lazy[currPos] != 0)
    {
        tree[currPos] += lazy[currPos];
        if (start != end) //condition to check node is not leaf node
        {
            lazy[2 * currPos] += lazy[currPos];
            lazy[2 * currPos + 1] += lazy[currPos];
        }
        lazy[currPos] = 0;
    }
    //no overlap
    if (startR > end || endR > start)
    {
        return;
    }

    //complete overlap
    if (startR <= start && endR >= end)
    {
        tree[currPos] += inc;
        if (start != end)
        {
            lazy[2 * currPos] += inc;
            lazy[2 * currPos + 1] += inc;
        }
        return;
    }
    //partial overlap

    int mid = (start + end) / 2;
    lazyf(tree, lazy, start, mid, startR, endR, currPos * 2, inc);
    lazyf(tree, lazy, mid + 1, end, startR, endR, currPos * 2 + 1, inc);
    tree[currPos] = min(tree[2 * currPos], tree[2 * currPos + 1]);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *tree = new int[18];
    int *lazy = new int[18];
    buildtree(arr, tree, 0, 8, 1);
    updatetree(arr, tree, 0, 8, 1, 2, 10);

    for (int i = 1; i < 18; ++i)
    {
        cout << tree[i] << endl;
    }
    int ans = query(tree, 0, 8, 1, 3, 5);
    cout << "sum:" << ans << endl;

    lazyf(tree, lazy, 0, 18, 3, 4, 1, 2);
    cout << "lazy tree" << endl;
    for (int i = 0; i < 18; ++i)
    {
        cout << tree[i] << endl;
    }
    return 0;
}
