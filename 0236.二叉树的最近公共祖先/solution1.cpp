/*
* 在遇到p或q时即返回不是NULL
* 倘若一个节点左右都是NULL，表明他不是两个节点的祖先
* 如果节点左右都不是NULL，表明他是公共祖先
* 倘若只有一边不是NULL，另一边是NULL，则表明公共祖先在不是NULL的一边
* 通过递归实现
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root==NULL || root==p || root==q)
            return root;
        TreeNode *left=lowestCommonAncestor(root->left,p,q);
        TreeNode *right=lowestCommonAncestor(root->right,p,q);
        if (left==NULL && right==NULL)
            return NULL;
        else if (left!=NULL && right!=NULL)
            return root;
        else if (left==NULL && right!=NULL)
            return right;
        else if (left!=NULL && right==NULL)
            return left;
        //无效return
        return NULL;
    }
};
