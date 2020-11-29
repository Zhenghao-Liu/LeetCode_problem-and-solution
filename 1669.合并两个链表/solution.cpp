/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode * st=list1;
        int aa=a-1;
        while (aa>0)
        {
            st=st->next;
            --aa;
        }
        ListNode * ed=st;
        int bb=b-a+1;
        while (bb>0)
        {
            ed=ed->next;
            --bb;
        }
        ListNode * r=ed->next;
        ed->next=NULL;
        st->next=list2;
        ListNode * p=list2;
        while (p->next!=NULL)
            p=p->next;
        p->next=r;
        return list1;
    }
};
