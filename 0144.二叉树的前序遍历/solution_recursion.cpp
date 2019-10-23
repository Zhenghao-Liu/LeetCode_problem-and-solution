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
        vector<int> answer;
        if (root==NULL)
            return {};
        DLR_travel(answer,root);
        return answer;
    }
    void DLR_travel(vector<int> & answer,TreeNode* p)
    {
        if (p!=NULL)
            answer.push_back(int(p->val));
        if (p->left!=NULL)
            DLR_travel(answer,p->left);
        if (p->right!=NULL)
            DLR_travel(answer,p->right);
    }
};
