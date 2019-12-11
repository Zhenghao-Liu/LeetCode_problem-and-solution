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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode * root=new ListNode(5201314);
        root->next=head;
        ListNode * p=root;
        while (p!=NULL && p->next!=NULL)
            if (p->next->val==val)
                p->next=p->next->next;
            else
                p=p->next;
        return root->next;
    }
};
