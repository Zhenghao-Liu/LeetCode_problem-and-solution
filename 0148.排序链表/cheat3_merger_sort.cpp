//[归并排序介绍](https://www.bilibili.com/video/av9982752?from=search&seid=4947641030506259389)
//归并排序,如果是采用数组空间复杂度为O(N)
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
        merge_sort(list_vector,0,list_vector.size()-1);
        p=head;
        for (int &i:list_vector)
        {
            if (p->val!=i)
                p->val=i;
            p=p->next;
        }
        return head;
    }
    void merge_sort(vector<int>& list_vector,int left,int right)
    {
        if (left>=right)
            return;
        int mid=(left+right)/2;
        merge_sort(list_vector,left,mid);
        merge_sort(list_vector,mid+1,right);
        merge(list_vector,left,right);
    }
    void merge(vector<int>& list_vector,int left,int right)
    {
        int mid=(left+right)/2;
        vector<int> left_part;
        for (int i=left;i<=mid;++i)
            left_part.push_back(list_vector.at(i));
        vector<int> right_part;
        for (int i=mid+1;i<=right;++i)
            right_part.push_back(list_vector.at(i));
        int left_part_i=0,right_part_i=0,list_vector_i=left;
        int left_part_size=mid-left+1,right_part_size=right-mid;
        for (;left_part_i<left_part_size && right_part_i<right_part_size;++list_vector_i)
            if (left_part.at(left_part_i)<=right_part.at(right_part_i))
                list_vector.at(list_vector_i)=left_part.at(left_part_i++);
            else
                list_vector.at(list_vector_i)=right_part.at(right_part_i++);
        while (left_part_i<left_part_size)
        {
            list_vector.at(list_vector_i)=left_part.at(left_part_i++);
            ++list_vector_i;
        }
        while (right_part_i<right_part_size)
        {
            list_vector.at(list_vector_i)=right_part.at(right_part_i++);
            ++list_vector_i;
        }
    }
};
