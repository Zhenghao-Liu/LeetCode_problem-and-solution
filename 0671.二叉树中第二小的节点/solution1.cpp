//暴力遍历两次
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
    int min_v;
    int ans;
    bool judge;
public:
    int findSecondMinimumValue(TreeNode* root) {
        min_v=INT_MAX;
        ans=INT_MAX;
        judge=false;
        dfs(root);
        dfs_2(root);
        return !judge ? -1 : ans;
    }
    void dfs(TreeNode * node)
    {
        if (node==NULL)
            return;
        min_v=min(min_v,node->val);
        dfs(node->left);
        dfs(node->right);
    }
    void dfs_2(TreeNode * node)
    {
        if (node==NULL)
            return;
        if (node->val>min_v)
        {
            judge=true;
            ans=min(ans,node->val);
        }  
        dfs_2(node->left);
        dfs_2(node->right);
    }

};
