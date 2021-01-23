// 一次遍历，且空间O（1）
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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode * a=head;
        while (k>1) {
            a=a->next;
            k--;
        }
        ListNode * fast=a;
        ListNode * b=head;
        while (fast->next!=NULL) {
            fast=fast->next;
            b=b->next;
        }
        swap(a->val,b->val);
        return head;
    }
};
