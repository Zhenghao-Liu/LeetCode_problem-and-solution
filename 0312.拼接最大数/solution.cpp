/*
* 一个可以比较字典序的STL函数
* [lexicographical_compare(iterator,iterator,iterator,iterator);](https://baike.baidu.com/item/lexicographical_compare)
* 将k分成nums1一部分长度为i求最大数的可能，nums2一部分长度为k-i求最大数的可能
* 比较所有的可能i，来寻找最大数
*/
class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int nums1_size=nums1.size(),nums2_size=nums2.size();
        vector<int> answer(k,0);
        for (int i=0,j=k;i<=nums1_size && j>=0;i++,--j)
        {
            if (j>nums2_size)
                continue;
            vector<int> ans_nums1=helper(nums1,i);
            vector<int> ans_nums2=helper(nums2,j);
            vector<int> result;
            vector<int>::iterator p_1=ans_nums1.begin(),p_2=ans_nums2.begin();
            //很巧妙的通过比较字典序来合成最大数，注意例子2
            while (p_1!=ans_nums1.end() || p_2!=ans_nums2.end())
                if (lexicographical_compare(p_1,ans_nums1.end(),p_2,ans_nums2.end()))
                {
                    result.push_back(*p_2);
                    ++p_2;
                }
                else
                {
                    result.push_back(*p_1);
                    ++p_1;
                }
            if (lexicographical_compare(answer.begin(),answer.end(),result.begin(),result.end()))
                answer=result;
        }
        return answer;
    }
    vector<int> helper(vector<int>& n,int k)
    {
        int n_size=n.size();
        if (n_size<k || k==0)
            return {};
        else if (n_size==k)
            return n;
        //记录最多可去除多少个个元素
        int pop=n_size-k;
        vector<int> ans;
        for (int i=0;i<n_size;++i)
        {
            while (!ans.empty() && n.at(i)>ans.back() && pop>0)
            {
                ans.pop_back();
                --pop;
            }
            ans.push_back(n.at(i));
        }
        //有可能降序的排列，就一直只进栈不出栈，导致栈东西多于要求长度
        ans.resize(k);
        return ans;
    }
};
