/*
* 采用迭代
* 二叉搜索树性质：中序遍历是有序的，即左左节点<当前节点<右节点
* 如果p和q都小于当前节点值，表明最近公共祖先在当前节点的左子节点中
* 如果都大于当前节点，则在右子节点
* 倘若一个大于一个小于，则当前节点就是公共祖先
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
        while (root!=NULL)
        {
            if (p->val<root->val && q->val<root->val)
                root=root->left;
            else if (p->val>root->val && q->val>root->val)
                root=root->right;
            else 
                return root;
        }
        return root;
    }
};
