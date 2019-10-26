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
        if (head->next==NULL)
        {
            TreeNode* root=new TreeNode(head->val);
            root->left=NULL;
            root->right=NULL;
            return root;
        }
        ListNode* fast,*slow;
        fast=slow=head;
        ListNode * temporary=new ListNode(0);
        temporary->next=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
            temporary=temporary->next;
        }
        TreeNode* root=new TreeNode(slow->val);
        temporary->next=NULL;
        root->left=sortedListToBST(head);
        root->right=sortedListToBST(slow->next);
        return root;
    }
};
