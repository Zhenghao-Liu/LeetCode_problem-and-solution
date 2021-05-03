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
public:
    int minDiffInBST(TreeNode* root) {
        int ans=INT_MAX;
        int last=INT_MIN/2;
        dfs(root,ans,last);
        return ans;
    }
    void dfs(TreeNode * node,int &ans,int& last)
    {
        if (node==nullptr)
            return;
        dfs(node->left,ans,last);
        ans=min(ans,node->val-last);
        last=node->val;
        dfs(node->right,ans,last);
    }
};