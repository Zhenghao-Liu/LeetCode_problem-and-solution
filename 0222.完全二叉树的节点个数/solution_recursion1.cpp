//快是快，但是没有利用到完全二叉树性质
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
    int countNodes(TreeNode* root) {
        if (root==NULL)
            return 0;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};
