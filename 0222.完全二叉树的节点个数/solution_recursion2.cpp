/*
* 把完全二叉树当一个三角形来看
* 那么如果左下角和右下角是在同一层
* 则是一颗满二叉树，则节点个数为pow(2,深度)-1
* 如果不在同一层，那么递归就好了，总会递归出现满二叉树的
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
    int countNodes(TreeNode* root) {
        if (root==NULL)
            return 0;
        TreeNode* left_node=root;
        int left_height=0;
        while (left_node!=NULL)
        {
            left_node=left_node->left;
            ++left_height;
        }
        TreeNode* right_node=root;
        int right_height=0;
        while (right_node!=NULL)
        {
            right_node=right_node->right;
            ++right_height;
        }
        if (left_height==right_height)
            //return pow(2,left_height)-1;因为左移一位就相当于乘2
            return (1<<left_height)-1;
        else
            return 1+countNodes(root->left)+countNodes(root->right);
    }
};
