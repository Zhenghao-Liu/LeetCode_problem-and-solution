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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode *> helper;
        int ans;
        helper.push(root);
        while (!helper.empty())
        {
            int size=helper.size();
            TreeNode *p;
            for (int i=0;i<size;++i)
            {
                p=helper.front();
                helper.pop();
                if (i==0)
                    ans=p->val;
                if (p->left!=NULL)
                    helper.push(p->left);
                if (p->right!=NULL)
                    helper.push(p->right);
            }
        }
        return ans;
    }
};
