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
    int goodNodes(TreeNode* root) {
        int ans=0;
        dfs(root,INT_MIN,ans);
        return ans;
    }
    void dfs(TreeNode* root,int max_v,int &ans)
    {
        if (root==NULL)
            return;
        if (max_v<=root->val)
            ++ans;
        max_v=max(max_v,root->val);
        dfs(root->left,max_v,ans);
        dfs(root->right,max_v,ans);
    }
};
