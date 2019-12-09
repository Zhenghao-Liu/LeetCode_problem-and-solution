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
    ListNode* swapPairs(ListNode* head) {
        if (head==NULL || head->next==NULL)
            return head;
        ListNode* one_before_left=head,*left=head,*right=head->next;
        head=head->next;
        left->next=right->next;
        right->next=left;
        if (left->next==NULL || left->next->next==NULL)
            return head;
        else
            swapPairs_two(left->next,left->next->next,one_before_left);          
        return head;
    }
    void swapPairs_two(ListNode* left,ListNode* right,ListNode* one_before_left)
    {
        one_before_left->next=right;
        one_before_left=left;
        left->next=right->next;
        right->next=left;
        if (left->next==NULL || left->next->next==NULL)
            return;
        else
            swapPairs_two(left->next,left->next->next,one_before_left);
    }
};
