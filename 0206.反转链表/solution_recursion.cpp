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
    ListNode* reverseList(ListNode* head) {
        //if (head==NULL || head->next==NULL)
        //    return head;
        return get_reverse(NULL,head);
    }
    ListNode* get_reverse(ListNode *left,ListNode *right)
    {
        if (right==NULL)
            return left;
        ListNode *p=right->next;
        right->next=left;
        return get_reverse(right,p);
    }
};
