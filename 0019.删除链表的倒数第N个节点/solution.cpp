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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (n==0)
            return head;
        int number=1;
        ListNode* pointer=head;
        while (pointer->next!=NULL)
        {
            ++number;
            pointer=pointer->next;
        }
        if (number==n)
            return head->next;
        pointer=head;
        for (int i=1;i<number-n;++i)
            pointer=pointer->next;
        pointer->next=pointer->next->next;
        return head;
    }
};
