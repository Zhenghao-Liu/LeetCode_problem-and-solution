class Solution {
    vector<int>::iterator p;
    int nums_size;
public:
    Solution(vector<int>& nums) {
        p=nums.begin();
        nums_size=nums.size();
    }
    
    int pick(int target) {
        int index=rand()%nums_size+0;
        while (*(p+index)!=target)
            index=rand()%nums_size+0;
        return index;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
