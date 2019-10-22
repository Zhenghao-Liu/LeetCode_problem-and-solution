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
    ListNode* partition(ListNode* head, int x) {
        ListNode *slow=new ListNode(0);
        slow->next=head;
        ListNode *fast=slow,*p;
        while (fast->next!=NULL && fast->next->val<x)
            fast=fast->next;
        slow=fast;
        while (fast->next!=NULL)
        {
            while (fast->next!=NULL && fast->next->val>=x)
                fast=fast->next;
            if (fast->next!=NULL)
            {
                p=fast->next;
                fast->next=p->next;
                p->next=slow->next;
                if (slow->next==head)
                    head=p;
                slow->next=p;
                slow=slow->next;
            }
        }
        return head;
    }
};
