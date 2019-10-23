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
    bool isSymmetric(TreeNode* root) {
        return check_symmetric(root,root);
    }
    bool check_symmetric(TreeNode* p,TreeNode* q)
    {
        if (p==NULL)
            return q==NULL;
        else if (q==NULL)
            return p==NULL;
        return (p->val==q->val && check_symmetric(p->left,q->right) && check_symmetric(p->right,q->left));
    }
};
