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
    ListNode* insertionSortList(ListNode* head) {
        if (head==NULL || head->next==NULL)
            return head;
        ListNode * root=new ListNode(INT_MAX);
        root->next=head;
        ListNode * previous=head;
        head=head->next;
        ListNode *p,*q;
        while (head!=NULL)
        {
            p=head;
            q=root;
            head=head->next;
            while (q->next!=p && q->next->val<p->val)
                q=q->next;
            if (q->next==p)
            {
                previous=previous->next;
                continue;
            }
            previous->next=head;
            p->next=q->next;
            q->next=p;
        }
        return root->next;
    }
};
