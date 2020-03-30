/*
* 对每个节点存在哈希表中剪枝
* 每个节点有两种情况
  1. 偷这个节点，那么当前节点的左右孩子不能偷，考虑左右孩子的孩子们的最大可能，再加上当前节点值
  2. 不偷这个节点，考虑当前节点的左右孩子的最大可能
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
