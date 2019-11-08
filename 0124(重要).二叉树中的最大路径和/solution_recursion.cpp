//参考下题解，题解讲得很详细
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
    int maxPathSum(TreeNode* root) {
        int answer=INT_MIN;
        find_maxPathSum(root,answer);
        return answer;
    }
    int find_maxPathSum(TreeNode* root,int & answer)
    {
        if (root==NULL)
            return 0;
        int left=find_maxPathSum(root->left,answer);
        int right=find_maxPathSum(root->right,answer);
        int without_root_root=root->val+left+right;
        int with_root_root=root->val+max(0,max(left,right));
        answer=max(answer,max(without_root_root,with_root_root));
        return with_root_root;
    }
};
