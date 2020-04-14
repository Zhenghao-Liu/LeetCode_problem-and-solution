//翻转两个链表，求和后，再翻转
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=reverseList(l1);
        l2=reverseList(l2);
        int carry=0;
        ListNode *p_l1=new ListNode(-1);
        p_l1->next=l1;
        ListNode *p_l2=new ListNode(-1);
        p_l2->next=l2;
        while (p_l1->next!=NULL && p_l2->next!=NULL)
        {
            int sum=carry+p_l1->next->val+p_l2->next->val;
            p_l1->next->val=sum%10;
            carry=sum/10;
            p_l1=p_l1->next;
            p_l2=p_l2->next;
        }
        if (p_l1->next==NULL && p_l2->next!=NULL)
            p_l1->next=p_l2->next;
        while (carry!=0 && p_l1->next!=NULL)
        {
            int sum=p_l1->next->val+carry;
            p_l1->next->val=sum%10;
            carry=sum/10;
            p_l1=p_l1->next;
        }
        if (carry!=0 && p_l1->next==NULL)
            p_l1->next=new ListNode(1);
        return reverseList(l1);
    }
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
