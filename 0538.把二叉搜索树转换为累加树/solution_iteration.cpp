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
    TreeNode* convertBST(TreeNode* root) {
        if (root==NULL)
            return NULL;
        stack<TreeNode *>helper;
        TreeNode *p=root;
        int sum=0;
        while (p!=NULL || !helper.empty())
        {
            if (p!=NULL)
            {
                helper.push(p);
                p=p->right;
            }
            else
            {
                p=helper.top();
                helper.pop();
                sum+=p->val;
                p->val=sum;
                p=p->left;
            }
        }
        return root;
    }
};
