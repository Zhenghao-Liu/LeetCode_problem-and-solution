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
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root==NULL)
            return {};
        vector<string> answer;
        if (root->left!=NULL)
            get_ans(root->left,answer,to_string(root->val));
        if (root->right!=NULL)
            get_ans(root->right,answer,to_string(root->val));
        if (root->left==NULL && root->right==NULL)
            answer.push_back(to_string(root->val));
        return answer;
    }
    void get_ans(TreeNode * root,vector<string>& answer,string temp)
    {
        temp=temp+"->"+to_string(root->val);
        if (root->left!=NULL)
            get_ans(root->left,answer,temp);
        if (root->right!=NULL)
            get_ans(root->right,answer,temp);
        if (root->left==NULL && root->right==NULL)
        {
            answer.push_back(temp);
            return;
        }
    }
};
