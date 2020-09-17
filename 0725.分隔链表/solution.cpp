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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        ListNode * p=root;
        int size=0;
        while (p!=NULL)
        {
            p=p->next;
            ++size;
        }
        vector<ListNode*> ans(k);
        if (size==0 || root==NULL)
            return ans;
        // size/k=quotient·····remainder
        int quotient=size/k;
        int remainder=size%k;
        int index=0;
        ListNode * dummy=new ListNode(-1);
        dummy->next=root;
        for (int i=0;i<k;++i)
        {
            int wanted_size=remainder>0 ? quotient+1 : quotient;
            --remainder;
            if (wanted_size==0 || dummy->next==NULL)
                break;
            ListNode * poi=dummy;
            while (wanted_size>0)
            {
                poi=poi->next;
                --wanted_size;
            }
            ListNode * nxt=poi->next;
            poi->next=NULL;
            ans.at(index)=dummy->next;
            ++index;
            dummy->next=nxt;
        }
        return ans;
    }
};
