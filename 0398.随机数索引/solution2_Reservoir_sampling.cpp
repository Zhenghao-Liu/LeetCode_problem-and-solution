class Solution {
    vector<int>::iterator start;
    int nums_size;
public:
    Solution(vector<int>& nums) {
        start=nums.begin();
        nums_size=nums.size();
    }
    
    int pick(int target) {
        vector<int>::iterator p=start;
        int ans=-1;
        int count=0;
        for (int i=0;i<nums_size;++i,++p)
            if ((*p)==target)
            {
                ++count;
                if (rand()%count==0)
                    ans=i;
            }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
