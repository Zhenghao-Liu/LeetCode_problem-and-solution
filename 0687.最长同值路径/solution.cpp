/*
* ans记录包括当前节点在考虑范围内（路径不一定包含当前节点）的，最长同值路径的长度
* 递归返回的是，包含当前节点的最长同值路径，且改路径是单边的，不会同时包含左右子树
*/
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
    int longestUnivaluePath(TreeNode* root) {
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
        int cur=0;
        int return_ans=0;
        if (node->left!=NULL && node->val==node->left->val)
        {
            cur+=left+1;
            return_ans=max(return_ans,left+1);
        }
        if (node->right!=NULL && node->val==node->right->val)
        {
            cur+=right+1;
            return_ans=max(return_ans,right+1);
        }
        ans=max(ans,cur);
        return return_ans;
    }
};
