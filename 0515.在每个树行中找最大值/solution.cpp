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
    vector<int> largestValues(TreeNode* root) {
        if (root==NULL)
            return {};
        vector<int>ans;
        queue<TreeNode *> helper;
        helper.push(root);
        while (!helper.empty())
        {
            int size=helper.size();
            TreeNode *p;
            int max_num=INT_MIN;
            for (int i=0;i<size;++i)
            {
                p=helper.front();
                helper.pop();
                max_num=max(max_num,p->val);
                if (p->left!=NULL)
                    helper.push(p->left);
                if (p->right!=NULL)
                    helper.push(p->right);
            }
            ans.push_back(max_num);
        }
        return ans;
    }
};
