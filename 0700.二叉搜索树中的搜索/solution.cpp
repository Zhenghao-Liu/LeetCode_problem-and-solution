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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root==NULL)
            return NULL;
        if (root->val==val)
            return root;
        if (val>root->val)
            return searchBST(root->right,val);
        else
            return searchBST(root->left,val);
        return 0;
    }
};
