/*
* 利用根节点是孩子节点的较小值这个性质
* 特殊情况：没有孩子，根是NULL
* 如果根节点和左孩子节点值相同，那么说明左孩子需要递归
  右孩子同样
* 看递归后是返回-1还是有值
* 若左右孩子都有值，因为是第二小，且当前根是第一小了，所以比较min(l,r)
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        if (root==NULL)
            return -1;
        if (root->left==NULL && root->right==NULL)
            return -1;
        int l=root->left->val;
        int r=root->right->val;
        if (root->val==l)
            l=findSecondMinimumValue(root->left);
        if (root->val==r)
            r=findSecondMinimumValue(root->right);
        if (l==-1)
            return r;
        if (r==-1)
            return l;
        return min(l,r);
    }
};
