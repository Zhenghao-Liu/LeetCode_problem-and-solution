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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head==NULL)
            return head;
        int listnode_size=1;
        ListNode* pointer_fast=head,*pointer_slow=head;
        //因为有报错原因所以写法有点别扭
        //直接看成while(pointer_fast->next->next!=NULL)，且里面没有if那一行即可
        while (pointer_fast->next!=NULL)
        {
            if (pointer_fast->next->next!=NULL)
            {
                pointer_fast=pointer_fast->next->next;
                pointer_slow=pointer_slow->next;
                listnode_size=listnode_size+2;
            }
            else
                break;  
        }
        if (pointer_fast->next!=NULL)
        {
            pointer_fast=pointer_fast->next;
            ++listnode_size;
        }
        //实际移动次数，但要找的是倒数第k+1个节点
        k=k-k/listnode_size*listnode_size;
        if (k==0 || listnode_size==1)
            return head;
        pointer_fast->next=head;
        if (k>listnode_size/2)//前半段
        {
            //pointer_fast作为一个工具指针，不再指向最后一个节点
            pointer_fast=head;
            for (int i=listnode_size-k-1;i>0;--i)
                pointer_fast=pointer_fast->next;
            head=pointer_fast->next;
            pointer_fast->next=NULL;
        }
        else//后半段
        {
            for (int i=listnode_size/2-k;i>0;--i)
                pointer_slow=pointer_slow->next;
            head=pointer_slow->next;
            pointer_slow->next=NULL;
        }
        return head;
    }
};
