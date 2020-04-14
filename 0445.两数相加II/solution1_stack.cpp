//取值进入栈中
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p1=l1,*p2=l2;
        stack<int> s1;
        while (p1!=NULL)
        {
            s1.push(p1->val);
            p1=p1->next;
        }
        stack<int> s2;
        while (p2!=NULL)
        {
            s2.push(p2->val);
            p2=p2->next;
        }
        ListNode *p=new ListNode(1),*helper=NULL;
        int carry=0;
        while (!s1.empty() || !s2.empty())
        {
            if (!s1.empty())
            {
                carry+=s1.top();
                s1.pop();
            }
            if (!s2.empty())
            {
                carry+=s2.top();
                s2.pop();
            }
            ListNode * node=new ListNode(carry%10);
            p->next=node;
            node->next=helper;
            helper=node;
            carry/=10;
        }
        if (carry!=0)
            return p;
        else
            return p->next;
    }
};
