//采用lc自带的单链表模板，模拟即可
// struct ListNode
// {
// 	int val;
// 	ListNode *next;
// 	ListNode(int _val) : val(_val) { next = NULL; }
// };
class MyLinkedList {
    ListNode * dummy;
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        dummy=new ListNode(-1);
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        ListNode *p=dummy->next;
        while (index>0 && p!=NULL)
        {
            p=p->next;
            --index;
        }
        return p==NULL ? -1 : p->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode * dummy_next=dummy->next;
        dummy->next=new ListNode(val);
        dummy->next->next=dummy_next;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ListNode * p=dummy;
        while (p->next!=NULL)
            p=p->next;
        p->next=new ListNode(val);
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index<0)
        {
            addAtHead(val);
            return;
        }
        ListNode *p=dummy;
        while (index>0 && p->next!=NULL)
        {
            p=p->next;
            --index;
        }
        if (p->next==NULL && index>0)
            return;
        ListNode * p_next=p->next;
        p->next=new ListNode(val);
        p->next->next=p_next;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index<0)
            return;
        ListNode *p=dummy;
        while (index>0 && p->next!=NULL)
        {
            p=p->next;
            --index;
        }
        if (p->next==NULL)
            return;
        p->next=p->next->next;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
