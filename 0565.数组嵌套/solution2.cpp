//方法同solution1，优化空间，直接走过的点设为-1，不用use标记
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int nums_size=nums.size();
        int ans=1;
        for (int i=0;i<nums_size;++i)
            if (nums.at(i)!=-1)
            {
                int cur=1;
                int begin=nums.at(i);
                int j=nums.at(begin);
                nums.at(begin)=-1;
                while (j!=begin)
                {
                    int next_pos=nums.at(j);
                    nums.at(j)=-1;
                    j=next_pos;
                    ++cur;
                }
                ans=max(ans,cur);
            }
        return ans;
    }
};
