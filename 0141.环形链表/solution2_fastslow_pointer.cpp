//如果有环，那么快的指针迟早会和慢的指针相遇
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
    bool hasCycle(ListNode *head) {
        if (head==NULL)
            return false;
        ListNode* slow,*fast;
        slow=head;
        fast=head->next;
        while (slow!=NULL && fast!=NULL)
        {
            if (slow==fast)
                return true;
            slow=slow->next;
            if (fast->next!=NULL)
                fast=fast->next->next;
            else
                return false;
        } 
        return false;
    }
};
