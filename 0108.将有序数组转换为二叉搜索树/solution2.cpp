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
    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        int nums_size=nums.size();
        if (nums_size==0)
            return NULL;
        int * nums_m=new int[nums_size];
        for (int i=0;i<nums_size;++i)
            nums_m[i]=nums.at(i);
        TreeNode* root=to_build(nums_m,nums_m+nums_size-1);
        delete []nums_m;
        return root;
    }
    TreeNode* to_build(int * left,int * right)
    {
        if (left>right)
            return NULL;
        int index=(right-left+1)/2;
        TreeNode * root=new TreeNode(*(left+index));
        if (right==left)
        {
            root->left=NULL;
            root->right=NULL;
            return root;
        }
        root->left=to_build(left,left+index-1);
        root->right=to_build(left+index+1,right);
        return root;
    }
};
