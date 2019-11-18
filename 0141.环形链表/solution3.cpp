//非常秀的做法，但要保证里面的值不存在自己设定的值
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
    bool hasCycle(ListNode *head) {
        while (head!=NULL)
        {
            if (head->val==5201314)
                return true;
            else
                head->val=5201314;
            head=head->next;
        }
        return false;  
    }
};
