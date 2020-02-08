//先用快慢指针找到有无重合的节点
//再从头开始、从重合点开始，两个再次相遇则为环的入口
//强推题解
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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow,*fast,*start;
        slow=fast=start=head;
        while (fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if (slow==fast)
            {
                while (start!=slow)
                {
                    start=start->next;
                    slow=slow->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};
