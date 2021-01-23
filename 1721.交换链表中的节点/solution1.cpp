/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        vector<ListNode *> vec;
        vec.reserve(1e5);
        ListNode *p=head;
        while (head!=NULL) {
            vec.push_back(head);
            head=head->next;
        }
        swap((vec.at(k-1))->val,(vec.at(vec.size()-k))->val);
        return p;
    }
};
