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
    int pathSum(TreeNode* root, int sum) {
        if (root==NULL)
            return 0;
        return pathSum(root->left,sum)+pathSum(root->right,sum)+helper(root,sum);
    }
    int helper(TreeNode * root,int sum)
    {
        if (root==NULL)
            return 0;
        int c=0;
        if (sum==root->val)
            c=1;
        int a=helper(root->left,sum-root->val);
        int b=helper(root->right,sum-root->val);
        return a+b+c;
    }
};
