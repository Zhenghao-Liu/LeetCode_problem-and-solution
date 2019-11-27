class MinStack {
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
    ListNode * stack_head,* sort_head;
public:
    /** initialize your data structure here. */
    MinStack() {
        stack_head=new ListNode(INT_MAX);
        sort_head=new ListNode(INT_MAX);
    }
    
    void push(int x) {
        ListNode* p=stack_head;
        while (p->next!=NULL)
            p=p->next;
        p->next=new ListNode(x);
        p=sort_head;
        while (p->next!=NULL && p->next->val<x)
            p=p->next;
        ListNode *insert_x=new ListNode(x);
        if (p->next!=NULL)
            insert_x->next=p->next;
        p->next=insert_x;
    }
    
    void pop() {
        ListNode* p=stack_head;
        while (p->next->next!=NULL)
            p=p->next;
        ListNode* delete_p=p->next;
        int delete_value=delete_p->val;
        p->next=NULL;
        delete delete_p;
        p=sort_head;
        while (p->next->next!=NULL && p->next->val!=delete_value)
            p=p->next;
        delete_p=p->next;
        p->next=delete_p->next;
        delete delete_p;
    }
    
    int top() {
        ListNode *p=stack_head;
        while (p->next!=NULL)
            p=p->next;
        return p->val;
    }
    
    int getMin() {
        return sort_head->next->val;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
