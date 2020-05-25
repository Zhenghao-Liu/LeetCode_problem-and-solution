//注意1<=a[i]<=n，所以可以用自身做哈希，即用负数来判别出现过一次，倘若出现判别为负数，即出现了两次数字
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for (int &i:nums)
        {
            int abs_i=abs(i);
            if (nums.at(abs_i-1)>0)
                nums.at(abs_i-1)*=-1;
            else
                ans.push_back(abs_i);
        }
        return ans;
    }
};
