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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> root_path;
        vector<int> answer({});
        while (root!=NULL || !root_path.empty())
            if (root!=NULL)
            {
                answer.push_back(int(root->val));
                root_path.push(root);
                root=root->left;
            }
            else
            {
                root=root_path.top();
                root_path.pop();
                root=root->right;
            }
        return answer;
    }
};
