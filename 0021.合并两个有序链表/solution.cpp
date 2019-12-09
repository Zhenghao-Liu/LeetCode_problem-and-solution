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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1==NULL)
            return l2;
        else if (l2==NULL)
            return l1;
        ListNode *ans;
        ListNode *head;
        if ( l1->val < l2->val )
        {
            head=ans=l1;
            l1=l1->next;     
        }
        else
        {
            head=ans=l2;
            l2=l2->next;
        } 
        while (l1!=NULL && l2!=NULL)
            if (l1->val < l2->val )
            {
                ans->next=l1;
                ans=ans->next;
                l1=l1->next;
            }
            else
            {
                ans->next=l2;
                ans=ans->next;
                l2=l2->next;
            }
        if (l1==NULL)
            ans->next=l2;
        else
            ans->next=l1;
        return head;    
    }
};
