//注意k==0的情况，这里是nums[j]-nums[i]>=0 以j为处理单元情况
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k<0)
            return 0;
        unordered_map<int,int> count;
        for (int &i:nums)
            ++count[i];
        int ans=0;
        for (auto &i:count)
        {
            if (k==0)
            {
                if (i.second>1)
                    ++ans;
            }
            else
            {
                if (count.find(i.first-k)!=count.end())
                    ++ans;
            }
        }
        return ans;
    }
};
