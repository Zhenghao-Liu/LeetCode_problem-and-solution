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
    int ans;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        ans=0;
        dfs(root);
        return ans;
    }
    int dfs(TreeNode *node)
    {
        if (node==NULL)
            return 0;
        int left=dfs(node->left);
        int right=dfs(node->right);
        ans=max(ans,left+right);
        return max(left,right)+1;
    }
};
