//转换成二叉树的最深深度来做
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
    int diameterOfBinaryTree(TreeNode* root) {
        if (root==NULL)
            return 0;
        int with_root=max_height(root->left)+max_height(root->right);
        return max(with_root,max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right)));
    }
    int max_height(TreeNode *root)
    {
        if (root==NULL)
            return 0;
        return max(max_height(root->left),max_height(root->right))+1;   
    }
};
