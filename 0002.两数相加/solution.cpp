static const auto SpeedUp = []{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
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
        ListNode*answer=new ListNode(0);
        ListNode *ans=answer;
        ListNode *former;
        int jinwei=0;
        while (l1!=NULL && NULL!=l2)
        {
            ans->val=(l1->val+l2->val+jinwei)%10;
            jinwei=(l1->val+l2->val+jinwei)/10;
            ListNode*p=new ListNode(0);
            ans->next=p;
            former=ans;
            ans=p;
            l1=l1->next;
            l2=l2->next;
        }
        if (NULL==l1)
            while (l2!=NULL)
            {
                ans->val=(l2->val+jinwei)%10;
                jinwei=(l2->val+jinwei)/10;
                ListNode*p=new ListNode(0);
                ans->next=p;
                former=ans;
                ans=p;
                l2=l2->next;
            }
        else
            while (l1!=NULL)
            {
                ans->val=(l1->val+jinwei)%10;
                jinwei=(l1->val+jinwei)/10;
                ListNode*p=new ListNode(0);
                ans->next=p;
                former=ans;
                ans=p;
                l1=l1->next;
            }
        ans->val=jinwei;
        if (0==ans->val)
                former->next=NULL;
        return answer;
    }
};
