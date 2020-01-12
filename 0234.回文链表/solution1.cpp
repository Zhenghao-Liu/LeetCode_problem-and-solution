//有点作弊。空间复杂度为O(N)
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
    bool isPalindrome(ListNode* head) {
        vector<int> v;
        while (head!=NULL)
        {
            v.push_back(head->val);
            head=head->next;
        }
        int v_size=v.size();
        for (int i=0;i<v_size/2;++i)
            if (v.at(i)!=v.at(v_size-1-i))
                return false;
        return true;
    }
};
