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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if (root==NULL)
            return NULL;
        int val=root->val;
        if (val<L || val>R)
        {
            if (root->right!=NULL)
            {
                TreeNode *p=root->right;
                while (p->left!=NULL)
                    p=p->left;
                p->left=root->left;
                root->left=NULL;
                return trimBST(root->right,L,R);
            }
            else
            {
                return trimBST(root->left,L,R);
            }
        }
        else
        {
            root->left=trimBST(root->left,L,R);
            root->right=trimBST(root->right,L,R);
            return root;
        }
        //无效return
        return NULL;
    }
};
