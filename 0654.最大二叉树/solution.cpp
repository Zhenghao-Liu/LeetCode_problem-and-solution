//模拟即可
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return helper(nums,0,nums.size()-1);
    }
    TreeNode * helper(vector<int>& nums,int start,int end)
    {
        if (start>end)
            return NULL;
        int max_pos=start;
        for (int i=start+1;i<=end;++i)
            if (nums.at(i)>nums.at(max_pos))
                max_pos=i;
        TreeNode * node=new TreeNode(nums.at(max_pos));
        node->left=helper(nums,start,max_pos-1);
        node->right=helper(nums,max_pos+1,end);
        return node;
    }
};
