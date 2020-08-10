//贪心：先找到的满足和为target的子数组就标记他的右边界，并且尽可能使哈希表中的位置靠右
class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        unordered_map<int,int> pos;
        pos[0]=-1;
        int prefix=0;
        int ans=0;
        int right=-2;
        int size=nums.size();
        for (int i=0;i<size;++i)
        {
            prefix+=nums.at(i);
            int t=prefix-target;
            if (pos.find(t)!=pos.end() && pos.at(t)>=right)
            {
                ++ans;
                right=i;
            }
            pos[prefix]=i;
        }
        return ans;
    }
};
