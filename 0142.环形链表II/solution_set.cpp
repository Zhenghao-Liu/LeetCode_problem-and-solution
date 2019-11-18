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
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode *> ListNode_set;
        while (head!=NULL)
        {
            if (ListNode_set.find(head)==ListNode_set.end())
                ListNode_set.insert(head);
            else
                return head;
            head=head->next;
        }
        return NULL; 
    }
};
