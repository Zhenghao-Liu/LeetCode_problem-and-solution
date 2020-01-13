/*
* 挺有意思一题
* 固定套路都是用前一个节点pre->next=pre->next->next
* 但现在没有给头节点，只给了一个单独要删除的节点
* 换种思路，我们把下一个节点信息复制到当前节点
* 然后删掉下一个节点就可以了
*/
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
    void deleteNode(ListNode* node) {
        node->val=node->next->val;
        node->next=node->next->next;
    }
};
