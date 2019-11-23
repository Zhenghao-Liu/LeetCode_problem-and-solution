//正确做法，用归并排序，空间复杂度因为是链表所以降低到O(1)
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
	if (head==NULL || head->next==NULL)
		return head;
	ListNode *slow,*fast;
	slow=head;
	fast=head->next;
	while (fast!=NULL && fast->next!=NULL)
	{
		slow=slow->next;
		fast=fast->next->next;
	}
	ListNode *right=slow->next;
	slow->next=NULL;
	head=sortList(head);
	right=sortList(right);
	head=merge(head,right);
	return head;
}
ListNode* merge(ListNode* left,ListNode* right)
{
	ListNode * root=new ListNode(INT_MAX),*p=root;
	while (left!=NULL && right!=NULL)
		if (left->val<=right->val)
		{
			p->next=left;
			p=p->next;
			left=left->next;
		}
		else
		{
			p->next=right;
			p=p->next;
			right=right->next;
		}
	if (left!=NULL)
		p->next=left;
	if (right!=NULL)
		p->next=right;
	p=root->next;
	delete root;
	return p;
}
};
