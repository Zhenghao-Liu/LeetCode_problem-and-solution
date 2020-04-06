class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>::iterator short_begin,short_end,long_begin,long_end;
        if (nums1.size()<nums2.size())
        {
            short_begin=nums1.begin();
            short_end=nums1.end();
            long_begin=nums2.begin();
            long_end=nums2.end();
        }
        else
        {
            short_begin=nums2.begin();
            short_end=nums2.end();
            long_begin=nums1.begin();
            long_end=nums1.end();
        }
        unordered_multiset<int> mask;
        for (auto i=long_begin;i!=long_end;++i)
            mask.insert(*i);
        vector<int> ans;
        for (auto i=short_begin;i!=short_end;++i)
        {
            unordered_multiset<int>::iterator p=mask.find(*i);
            if (p!=mask.end())
            {
                ans.push_back(*i);
                mask.erase(p);
            }
        }
        return ans;
    }
};
