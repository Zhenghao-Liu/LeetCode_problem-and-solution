/*
* [0]表示不偷当前节点
  [1]表示偷当前节点
* 所以对于当前节点
  [0]即左右孩子的最大可能(孩子可以偷也可以不偷，考虑最大)
  [1]即左右孩子不偷的最大可能加上当前节点值
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
private:
    unordered_map<TreeNode *,int> ans;
public:
    int rob(TreeNode* root) {
        return helper(root);
    }
    int helper(TreeNode * node)
    {
        if (node==NULL)
            return 0;
        if (ans.find(node)!=ans.end())
            return ans.at(node);
        int stole_this=node->val;
        if (node->left!=NULL)
            stole_this+=helper(node->left->left)+helper(node->left->right);
        if (node->right!=NULL)
            stole_this+=helper(node->right->left)+helper(node->right->right);
        int not_stole_this=helper(node->left)+helper(node->right);
        ans[node]=max(stole_this,not_stole_this);
        return ans.at(node);
    }
};
