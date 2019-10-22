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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m==n)
            return head;
        ListNode * slow=new ListNode(0);
        slow->next=head;
        ListNode *fast=slow;
        for (int i=1;i<m;++i)
            fast=fast->next;
        ListNode *tail=fast->next,*p;
        for (int i=m;i<n;++i)
        {
            p=tail->next;
            tail->next=p->next;
            p->next=fast->next;
            fast->next=p;
        }
        return slow->next;
    }
};
