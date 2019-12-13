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
        ListNode *left=NULL,*right=head,*p;
        while (right!=NULL)
        {
            p=right->next;
            right->next=left;
            left=right;
            right=p;
        }
        return left;
    }
};
