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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        return dfs(s,t);
    }
    bool dfs(TreeNode *s,TreeNode *t)
    {
        if (s==NULL)
            return false;
        return check(s,t) || dfs(s->left,t) || dfs(s->right,t);
    }
    bool check(TreeNode *s,TreeNode*t)
    {
        if (s==NULL && t==NULL)
            return true;
        if (s==NULL || t==NULL || s->val!=t->val)
            return false;
        return check(s->left,t->left) && check(s->right,t->right);
    }
};
