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
    int sumOfLeftLeaves(TreeNode* root) {
        stack<TreeNode*> helper;
        TreeNode *p=root;
        int ans=0;
        while (!helper.empty() || p!=NULL)
        {
            if (p!=NULL)
            {
                helper.push(p);
                if (p->left!=NULL && p->left->left==NULL && p->left->right==NULL)
                    ans+=p->left->val;
                p=p->left;
            }
            else
            {
                p=helper.top();
                p=p->right;
                helper.pop();
            }
        }
        return ans;
    }
};
