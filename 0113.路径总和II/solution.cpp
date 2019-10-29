//借用上一题的思路来做
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> answer;
        hasPathSum(root,sum,answer,{});
        return answer;
    }
    void hasPathSum(TreeNode* root, int sum,vector<vector<int>>& answer,vector<int> temporary) 
    {
        if (root==NULL)
            return;
        temporary.push_back(root->val);
        if (root->left==NULL && root->right==NULL && sum==root->val)
        {
            answer.push_back(temporary);
            return;
        }  
        hasPathSum(root->left,sum-root->val,answer,temporary);
        hasPathSum(root->right,sum-root->val,answer,temporary);
    }
};
