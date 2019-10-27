/*
* 注意测试案例[1,2]答案为2,即必须为叶子节点(左右子树均为空)
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
    int minDepth(TreeNode* root) {
        if (root==NULL)
            return 0;
        int left=minDepth(root->left);
        int right=minDepth(root->right);
        //如果有一边为空那么min的结果必定为0，所以要提前判断好子树是没有节点的情况
        if (root->left==NULL || root->right==NULL)
            return left+right+1;
        return 1+min(left,right);
    }
};
