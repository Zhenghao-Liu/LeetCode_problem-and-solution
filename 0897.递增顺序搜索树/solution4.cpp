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
    TreeNode * dummy;
    TreeNode * lst;
public:
    TreeNode* increasingBST(TreeNode* root) {
        dummy=new TreeNode(-1);
        lst=dummy;
        dfs(root);
        lst->left=lst->right=NULL;
        return dummy->right;
    }
    void dfs(TreeNode * node) {
        if (node==NULL) {
            return;
        }
        dfs(node->left);
        lst->left=NULL;
        lst->right=node;
        lst=node;
        dfs(node->right);
    }
};