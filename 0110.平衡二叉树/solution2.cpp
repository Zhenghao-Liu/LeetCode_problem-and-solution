//采用后序遍历方式自底向上
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
    bool isBalanced(TreeNode* root) {
        return maxDepth(root)>=0;
    }
    int maxDepth(TreeNode* root) {
        if (root==NULL)
            return 0;
        int left_depth=maxDepth(root->left);
        int right_depth=maxDepth(root->right);
        if (left_depth==-1 || right_depth==-1 || abs(left_depth-right_depth)>1)
            return -1;
        return 1+max(left_depth,right_depth);
    }
};
