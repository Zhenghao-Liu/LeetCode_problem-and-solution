/*
* 因为要按照先序(根左右)的顺序来展开链表
* 那就要按照反过来顺序(右左根)的方式来处理
* 用past记录前一个节点然后root->right=past
* 记得左子树置空
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
    void flatten(TreeNode* root) { 
        build_chain_table(root,NULL);
    }
    TreeNode* build_chain_table(TreeNode * root,TreeNode * last)
    {
        if (root==NULL)
            return last;
        last=build_chain_table(root->right,last);
        last=build_chain_table(root->left,last);
        root->right=last;
        root->left=NULL;
        return root;
    }
};
