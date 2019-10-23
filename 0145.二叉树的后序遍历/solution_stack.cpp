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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> answer;
        stack<TreeNode*> root_path;
        TreeNode* past=NULL;
        while (root!=NULL || !root_path.empty())
            if (root!=NULL)
            {
                root_path.push(root);
                root=root->left;
            }
            else
            {
                root=root_path.top();
                if (root->right==NULL || root->right==past)
                {
                    answer.push_back(root->val);
                    root_path.pop();
                    past=root;
                    root=NULL;
                }
                else
                    root=root->right;
            }
        return answer;
    }
};
