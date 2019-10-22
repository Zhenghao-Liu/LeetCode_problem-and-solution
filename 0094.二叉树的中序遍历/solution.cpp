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
        vector<int> answer;
        if (root!=NULL)
            LDR_travel(answer,root);
        return answer;
    }
    void LDR_travel(vector<int>& answer,TreeNode* root)
    {
        if (root->left!=NULL)
            LDR_travel(answer,root->left);
        answer.push_back(int(root->val));
        if (root->right!=NULL)
            LDR_travel(answer,root->right);
    }
};
