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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int lists_size=lists.size(),index=1;
        if (lists_size==0)
            return NULL;
        while (lists_size!=1)
        {
            for (int i=0;i+1<lists_size;i=i+2)
                lists.at(i)=mergeTwoLists(lists.at(i),lists.at(i+1));
            for(vector<ListNode*>::iterator iter=lists.begin()+1;index<lists_size;iter++,index=index+2)
                    iter=lists.erase(iter);
            index=1;
            lists_size=lists.size();
        }
        return lists.at(0);   
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        if (l1==NULL)
            return l2;
        else if (l2==NULL)
            return l1;
        ListNode *ans;
        ListNode *head;
        if ( l1->val < l2->val )
        {
            head=ans=l1;
            l1=l1->next;     
        }
        else
        {
            head=ans=l2;
            l2=l2->next;
        } 
        while (l1!=NULL && l2!=NULL)
            if (l1->val < l2->val )
            {
                ans->next=l1;
                ans=ans->next;
                l1=l1->next;
            }
            else
            {
                ans->next=l2;
                ans=ans->next;
                l2=l2->next;
            }
        if (l1==NULL)
            ans->next=l2;
        else
            ans->next=l1;
        return head;    
    }
};
