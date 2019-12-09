class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int nums_size=nums.size();
        if (nums_size<=1)
            return nums_size;
        int slow=0;
        for (int fast=0;fast<nums_size;)
        {
            nums.at(slow)=nums.at(fast);
            ++slow;
            ++fast;
            while (fast<nums_size && nums.at(fast)==nums.at(fast-1))
                fast=fast+1;
        }
        return slow;
    }
};
