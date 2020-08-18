//递归遍历时利用twosum的方法，但是没有用到BST的性质
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
    unordered_set<int> helper;
public:
    bool findTarget(TreeNode* root, int k) {
        helper.clear();
        return dfs(root,k);
    }
    bool dfs(TreeNode * node,int k)
    {
        if (node==NULL)
            return false;
        if (helper.find(k-(node->val))!=helper.end())
            return true;
        helper.insert(node->val);
        return dfs(node->left,k) || dfs(node->right,k);
    }
};
