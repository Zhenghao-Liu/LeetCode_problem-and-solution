//[deque介绍](https://www.cnblogs.com/linuxAndMcu/p/10260124.html)
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
        deque<ListNode*> list_deque;
        ListNode* p=head;
        while (p!=NULL)
        {
            list_deque.push_back(p);
            p=p->next;
        }
        p=list_deque.front();
        list_deque.pop_front();
        int index=0;
        while (!list_deque.empty())
        {
            if (index==0)
            {
                p->next=list_deque.back();
                list_deque.pop_back();
            }
            else
            {
                p->next=list_deque.front();
                list_deque.pop_front();
            }
            p=p->next;
            index=index^1;
        }
        p->next=NULL;
    }
};
