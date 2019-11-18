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
        unordered_set<ListNode *> ListNode_set;
        while (head!=NULL)
        {
            if (ListNode_set.find(head)==ListNode_set.end())
                ListNode_set.insert(head);
            else
                return true;
            head=head->next;
        }
        return false;  
    }
};
