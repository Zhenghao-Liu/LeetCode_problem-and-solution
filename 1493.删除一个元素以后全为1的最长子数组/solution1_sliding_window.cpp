/*
* 将nums压缩成window：将连续的1算出来，0不动
* 将window预处理成v：因为要删除，删除0是最优的，但是如果是多个连续的0只能删除一个0不能全删
* ans=max(ans,v.at(i)+v.at(i+1))注意下特殊情况：nums中没有0或者最后v只有一个元素情况
*/
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int> window;
        int nums_size=nums.size();
        for (int i=0;i<nums_size;++i)
        {
            if (nums.at(i)==1)
            {
                int origin=i;
                while (i<nums_size && nums.at(i)==1)
                    ++i;
                window.push_back(i-origin);
                if (i<nums_size)
                    --i;
            }
            else
            {
                window.push_back(0);
            }
        }
        vector<int> v;
        bool judge=false;
        bool judge_zero=false;
        for (int i:window)
        {
            if (i!=0)
            {
                v.push_back(i);
                judge=true;
            }
            else
            {
                judge_zero=true;
                if (judge)
                    judge=false;
                else
                    v.push_back(i);
            }
        }
        if (!judge_zero)
            return v.at(0)-1;
        if (nums.size()==1)
            return v.at(0);
        int ans=INT_MIN;
        for (int i=0;i<v.size()-1;++i)
            ans=max(ans,v.at(i)+v.at(i+1));
        return ans;
    }
};
