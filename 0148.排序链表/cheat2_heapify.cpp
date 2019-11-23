//[堆排序介绍](https://www.bilibili.com/video/av47196993?from=search&seid=17861995909061761507)
//采用数组的堆排序，空间复杂度为O(N)
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
        head_sort(list_vector,list_vector.size());
        p=head;
        for (int &i:list_vector)
        {
            if (p->val!=i)
                p->val=i;
            p=p->next;
        }
        return head;
    }
    void head_sort(vector<int>& list_vector,const int list_vector_size)
    {
        build_heap(list_vector,list_vector_size);
        for (int i=list_vector_size-1;i>=0;--i)
        {
            swap(list_vector.at(0),list_vector.at(i));
            heapify(list_vector,i,0);
        }
    }
    void heapify(vector<int>& list_vector,const int list_vector_size,int i)
    {
        if (i>=list_vector_size)
            return;
        int max=i;
        if (2*i+1<list_vector_size && list_vector.at(2*i+1)>list_vector.at(max))
            max=2*i+1;
        if (2*i+2<list_vector_size && list_vector.at(2*i+2)>list_vector.at(max))
            max=2*i+2;
        if (max!=i)
        {
            swap(list_vector.at(i),list_vector.at(max));
            heapify(list_vector,list_vector_size,max);
        }
    }
    void build_heap(vector<int>& list_vector,const int list_vector_size)
    {
        for (int i=(list_vector_size-1-1)/2;i>=0;--i)
            heapify(list_vector,list_vector_size,i);
    }
};
