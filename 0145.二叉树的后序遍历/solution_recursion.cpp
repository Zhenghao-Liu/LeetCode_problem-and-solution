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
        if (root!=NULL)
            LRD_travel(answer,root);
        return answer;
    }
    void LRD_travel(vector<int>& answer,TreeNode* root)
    {
        if (root->left!=NULL)
            LRD_travel(answer,root->left);
        if (root->right!=NULL)
            LRD_travel(answer,root->right);
        answer.push_back(int(root->val));
    }
};
