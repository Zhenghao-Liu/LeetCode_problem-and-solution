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
    TreeNode* convertBST(TreeNode* root) {
        int plus=0;
        dfs(root,plus);
        return root;
    }
    void dfs(TreeNode *node,int &plus)
    {
        if (node==nullptr)
            return;
        dfs(node->right,plus);
        int temp=plus+node->val;
        node->val+=plus;
        plus=temp;
        dfs(node->left,plus);
    }
};
