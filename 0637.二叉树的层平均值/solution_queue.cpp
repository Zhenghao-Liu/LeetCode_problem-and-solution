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
    vector<double> averageOfLevels(TreeNode* root) {
        if (root==NULL)
            return {};
        vector<double> ans;
        queue<TreeNode*> helper;
        helper.push(root);
        while (!helper.empty())
        {
            int size=helper.size();
            double sum=0;
            for (int i=0;i<size;++i)
            {
                TreeNode *p=helper.front();
                helper.pop();
                sum+=p->val;
                if (p->left!=NULL)
                    helper.push(p->left);
                if (p->right!=NULL)
                    helper.push(p->right);
            }
            ans.push_back(sum/size);
        }
        return ans;
    }
};
