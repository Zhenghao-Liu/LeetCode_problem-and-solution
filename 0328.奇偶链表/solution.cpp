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
    ListNode* oddEvenList(ListNode* head) {
        if (head==nullptr)
            return nullptr;
        ListNode * left=head;
        ListNode * right=head->next;
        ListNode * right_head=head->next;
        while (right!=nullptr && right->next!=nullptr)
        {
            left->next=right->next;
            right->next=right->next->next;
            left->next->next=right_head;
            left=left->next;
            right=right->next;
        }
        return head;
    }
};
