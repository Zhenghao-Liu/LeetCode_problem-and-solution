/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head)
    {
        if (head==0)
            return NULL;
        vector<int> nums;
        while(head!=NULL)
        {
            nums.push_back(head->val);
            head=head->next;
        }
        return to_build(nums,0,nums.size()-1);
    }
    TreeNode* to_build(vector<int>& nums,int left,int right)
    {
        if (left>right)
            return NULL;
        int index=(right+left)/2;
        TreeNode * root=new TreeNode(nums.at(index));
        if (right==left)
        {
            root->left=NULL;
            root->right=NULL;
            return root;
        }
        root->left=to_build(nums,left,index-1);
        root->right=to_build(nums,index+1,right);
        return root;
    }
};
