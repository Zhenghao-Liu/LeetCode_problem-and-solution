//因测试数据大多都是有序的，所以循环前直接用当前节点和前一个节点比一下，就不用每次都从头开始遍历
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
    ListNode* insertionSortList(ListNode* head) {
        if (head==NULL || head->next==NULL)
            return head;
        ListNode * root=new ListNode(INT_MAX);
        root->next=head;
        ListNode * previous=head;
        head=head->next;
        ListNode *p,*q;
        while (head!=NULL)
        {
            p=head;
            q=root;
            head=head->next;
            if (p->val>=previous->val)
            {
                previous=previous->next;
                continue;
            }
            while (q->next->val<p->val)
                q=q->next;
            previous->next=head;
            p->next=q->next;
            q->next=p;
        }
        return root->next;
    }
};
