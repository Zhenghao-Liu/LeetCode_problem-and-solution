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
    void reorderList(ListNode* head) {
        if (head==NULL)
            return;
        queue<ListNode*> backward;
        stack<ListNode*> fordward;
        ListNode* p=head;
        while (p!=NULL)
        {
            backward.push(p);
            fordward.push(p);
            p=p->next;
        }
        backward.pop();
        p=head;
        int index=0;
        ListNode* q=fordward.top();
        while (p!=q)
        {
            p->next=q;
            p=q;
            if (index==0)
            {
                fordward.pop();
                q=backward.front();
            }
            else
            {
               backward.pop();
               q=fordward.top();
            }
            index=index^1;
        }
        p->next=NULL;
    }
};
