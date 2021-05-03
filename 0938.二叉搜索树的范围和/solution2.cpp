/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int ans;
    int l,h;
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        ans=0;
        l=low;
        h=high;
        dfs(root);
        return ans;
    }
    void dfs(TreeNode *node) {
        if (node==NULL) {
            return;
        }
        dfs(node->left);
        if (node->val>=l && node->val<=h) {
            ans+=node->val;
        }
        dfs(node->right);
    }
};