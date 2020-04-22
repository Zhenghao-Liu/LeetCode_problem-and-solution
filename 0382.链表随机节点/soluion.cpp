/*
* 蓄水池抽样算法，即保证N个元素，每个元素被抽取概率相同
* 假设有N个元素，设只抽取一个数即k=1情况，即每个被抽取概率都是1/N
* 已经有一个数了，当轮到第i个数时，有1/i几率保留第i个数，即用第i个数替换原有的数
                                有1-1/i=(i-1)/i几率保留原来的数
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
    ListNode *_head;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        _head=head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int i=2;
        int _val=_head->val;
        ListNode * p=_head->next;
        while (p!=NULL)
        {
            //有1/i的几率保留第i个数，即用第i个数替换旧数
            if ((rand()%i+1)==1)
                _val=p->val;
            ++i;
            p=p->next;
        }
        return _val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
