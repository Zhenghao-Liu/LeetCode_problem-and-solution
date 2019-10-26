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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int nums_size=nums.size(),index=nums_size/2;
        if (nums_size==0)
            return NULL;
        TreeNode* root=new TreeNode(nums.at(index));
        if (nums_size==1)
        {
            root->left=NULL;
            root->right=NULL;
            return root;
        }
        vector<int> left(nums.begin(),nums.begin()+index);
        vector<int> right(nums.begin()+index+1,nums.end());
        root->left=sortedArrayToBST(left);
        root->right=sortedArrayToBST(right);
        return root;
    }
};
