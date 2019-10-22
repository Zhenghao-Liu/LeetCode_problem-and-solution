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
    vector<TreeNode*> generateTrees(int n) {
        if (n==0)
            return {};
        return helper(1,n);
    }
    vector<TreeNode*> helper(int left,int right)
    {
        if (left>right)
            return {NULL};
        vector<TreeNode*> answer;
        for (int i=left;i<=right;++i)
        {
            vector<TreeNode*> left_part=helper(left,i-1);
            vector<TreeNode*> right_part=helper(i+1,right);
            for (TreeNode* l:left_part)
                for (TreeNode* r:right_part)
                {
                    TreeNode* root=new TreeNode(i);
                    root->left=l;
                    root->right=r;
                    answer.push_back(root);
                }
        }
        return answer;
    }
};
