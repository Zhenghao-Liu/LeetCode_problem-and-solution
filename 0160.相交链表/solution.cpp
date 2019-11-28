/*
* 定义两个指针pa、pb为AB两条链头部
* 从头开始同步的往后走，当pa到达尾端时让他指向B链的头，同样当pb到达尾端时让他指向A链的头
* 二者相等的点即为相交的dian
* 可以这样理解
* 若两条链相交，则两条链的末尾最后一个节点必然是相同的
* 设A{a->c}、B{b->c}，ab指未相交的部分，c指相交的部分
* 那么pa走的路就是a+c+b
* pb走的就是b+c+a
* 最后pa==pb时必然是相交的节点
* 对于这题的这种写法，当两者不想交的情况
* 将会循环a、b链长度的最小公倍数，最后以pa==pa==NULL退出循环
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pa=headA,*pb=headB;
        while (pa!=pb)
        {
            pa= pa==NULL ? headB : pa->next;
            pb= pb==NULL ? headA : pb->next;
        }
        return pa;
    }
};
