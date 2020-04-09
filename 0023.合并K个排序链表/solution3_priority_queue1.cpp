//取值排序
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue <int,vector<int>,greater<int> > q;
        for (ListNode* &i:lists)
        {
            while (i!=NULL)
            {
                q.push(i->val);
                i=i->next;
            }
        }
        if (q.empty())
            return NULL;
        ListNode *head=new ListNode(q.top()),*p=head;
        q.pop();
        while (!q.empty())
        {
            p->next=new ListNode(q.top());
            p=p->next;
            q.pop();
        }
        return head;
    }
};
