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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> stack_roots;
        vector<int> answer;
        while(root!=NULL || !stack_roots.empty())
            if (root!=NULL)
            {
                stack_roots.push(root);
                root=root->left;
            }
            else
            {
                root=stack_roots.top();
                stack_roots.pop();
                answer.push_back(int(root->val));
                root=root->right;
            }
        return answer;
    }
};
