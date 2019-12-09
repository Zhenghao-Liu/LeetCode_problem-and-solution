/*
* 旋转k次，则有k个元素往前面走
* 将所有元素反转。然后反转前 k 个元素，再反转后面 n-k 个元素
*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int nums_size=nums.size();
        k=k%nums_size;
        if (nums_size<2 || k==0)
            return;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};
