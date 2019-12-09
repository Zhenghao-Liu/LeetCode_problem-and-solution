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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k==1)
            return head;
        ListNode* right=head;
        stack<ListNode*> ListsNode_stack;
        for (int i=0;i<k;++i)
            if (right==NULL)
                return head;
            else
            {
                ListsNode_stack.push(right);
                right=right->next;
            }
        head=ListsNode_stack.top();
        ListsNode_stack.pop();
        ListNode *index=head;
        for (int i=k-1;i>0;--i)
        {
            index->next=ListsNode_stack.top();
            index=index->next;
            ListsNode_stack.pop();
        }
        index->next=reverseKGroup(right,k);
        return head;
    }
};
