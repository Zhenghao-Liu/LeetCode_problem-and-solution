//快慢指针分割左右链表，将右链表反转，然后比较
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
    bool isPalindrome(ListNode* head) {
        if (head==NULL || head->next==NULL)
            return true;
        ListNode * slow=head;
        ListNode * fast=head->next;
        while (fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode * right=slow->next;
        slow->next=NULL;
        ListNode * past=NULL;
        while (right!=NULL)
        {
            ListNode *temp=right->next;
            right->next=past;
            past=right;
            right=temp;
        }
        right=past;
        while (right!=NULL)
        {
            if (head->val!=right->val)
                return false;
            head=head->next;
            right=right->next;
        }
        return true;
    }
};
