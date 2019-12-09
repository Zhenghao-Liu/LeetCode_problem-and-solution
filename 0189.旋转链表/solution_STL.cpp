class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int nums_size=nums.size();
        k=k%nums_size;
        std::rotate(nums.begin(),nums.end()-k,nums.end());
    }
};
