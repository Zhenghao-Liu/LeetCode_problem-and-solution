//不满足空间复杂度O(1)
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
    ListNode* sortList(ListNode* head) {
        vector<int> list_vector;
        ListNode* p=head;
        while (p!=NULL)
        {
            list_vector.push_back(int(p->val));
            p=p->next;
        }
        sort(list_vector.begin(),list_vector.end());
        p=head;
        for (int &i:list_vector)
        {
            if (p->val!=i)
                p->val=i;
            p=p->next;
        }
        return head;
    }
};
