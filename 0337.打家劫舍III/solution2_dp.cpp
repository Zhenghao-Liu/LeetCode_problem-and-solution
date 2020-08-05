/*
* [0]表示不偷当前节点
  [1]表示偷当前节点
* 所以对于当前节点
  [0]即左右孩子的最大可能(孩子可以偷也可以不偷，考虑最大)
  [1]即左右孩子不偷的最大可能加上当前节点值
* 采用pair构成返回类型速度会更快
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
public:
    int rob(TreeNode* root) {
        int* ans=helper(root);
        return max(ans[0],ans[1]);
    }
    int * helper(TreeNode* root)
    {
        int *dp=new int[2];
        dp[0]=dp[1]=0;
        if (root==NULL)
            return dp;
        int *left=helper(root->left);
        int *right=helper(root->right);
        dp[0]=max(left[0],left[1])+max(right[0],right[1]);
        dp[1]=root->val+left[0]+right[0];
        return dp;
    }
};
