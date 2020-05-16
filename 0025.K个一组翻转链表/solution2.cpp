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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k==1)
            return head;
        ListNode *p=head;
        ListNode *first=head;
        //计数：有可能这一段不够k个
        for (int i=0;i<k;++i,p=p->next)
            if (p==NULL)
                return head;
        ListNode * dummy=new ListNode(-1);
        dummy->next=head;
        p=dummy;
        ListNode *next_p;
        int loop=k;
        while (loop>0)
        {
            next_p=dummy->next->next;
            ListNode *q=dummy->next;
            q->next=p;
            dummy->next=next_p;
            p=q;
            --loop;
        }
        first->next=reverseKGroup(dummy->next,k);
        return p;
    }
};
