//把所有链表头节点放进优先队列排序，取出最小的，并将他的next再放入排序
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct cmp {
    bool operator()(ListNode* &A,ListNode* &B) {
        return (A->val)>(B->val);
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue <ListNode*,vector<ListNode*>,cmp> q;
        for (ListNode* &i:lists)
            if (i!=NULL)
                q.push(i);
        ListNode *head=new ListNode(0),*p=head;
        while (!q.empty())
        {
            ListNode *temp=q.top();
            q.pop();
            p->next=temp;
            p=p->next;
            if (temp->next!=NULL)
                q.push(temp->next);
        }
        return head->next;
    }
};
