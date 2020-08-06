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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1==NULL && t2==NULL)
            return NULL;
        TreeNode * node=new TreeNode(-1);
        if (t1!=NULL && t2==NULL)
        {
            node->val=t1->val;
            node->left=mergeTrees(t1->left,NULL);
            node->right=mergeTrees(t1->right,NULL);
            return node;
        }
        else if (t1==NULL && t2!=NULL)
        {
            node->val=t2->val;
            node->left=mergeTrees(NULL,t2->left);
            node->right=mergeTrees(NULL,t2->right);
            return node;
        }
        //else if (t1!=NULL && t2!=NULL)
        else
        {
            node->val=t1->val + t2->val;
            node->left=mergeTrees(t1->left,t2->left);
            node->right=mergeTrees(t1->right,t2->right);
            return node;
        }
        return NULL;
    }
};
