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
    bool isValidBST(TreeNode* root) {
        //设置每个节点的上界和下界
        //对于左孩子来说，上界就是左孩子的父节点
        //对于右孩子来说，下界就是右孩子的父节点
        return dfs(root,LONG_LONG_MIN,LONG_LONG_MAX);
    }
    bool dfs(TreeNode * root,long long lower,long long upper)
    {
        if (root==NULL)
            return true;
        if (root->val >= upper || root->val <= lower)
            return false;
        return dfs(root->left,lower,root->val) && dfs(root->right,root->val,upper);

    }
};
