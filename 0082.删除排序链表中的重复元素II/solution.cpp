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
    ListNode* deleteDuplicates(ListNode* head) {
		//防止都有重复的话要返回NULL
        ListNode *temporary=new ListNode(0);
        ListNode *slow=temporary,*fast=head;
        slow->next=head;
        while (fast!=NULL)
        {
            while (fast!=NULL && fast->next!=NULL && fast->val==fast->next->val)
            {
                while (fast->next!=NULL && fast->val==fast->next->val)
                    fast=fast->next;
                fast=fast->next;
            }
            if (fast!=NULL)
            {
                slow->next->val=fast->val;
                if (fast->next!=NULL)
                    slow=slow->next;
                else
                    slow->next->next=NULL;
                fast=fast->next;
            }
            else if (slow->next!=head)
                slow->next=NULL;
            else
                return NULL;
        }
        return head;
    }
};
