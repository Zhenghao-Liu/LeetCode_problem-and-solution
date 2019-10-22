/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *slow=head,*fast=head;
        while (fast!=NULL)
        {
            while (fast->next!=NULL && fast->val==fast->next->val)
                fast=fast->next;
            slow->val=fast->val;
            if (fast->next!=NULL)
                slow=slow->next;
            else
                slow->next=NULL;
            fast=fast->next;
        }
        return head;
    }
};
