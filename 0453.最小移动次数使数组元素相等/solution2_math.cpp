/*
* 每次移动会使n-1个元素加1
* 反向思维就是让1个元素减1
* 那最小移动次数就是让每个元素都移动到最小元素的值
* 所以加上每个元素和最小值的差值即可
*/
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min_val=INT_MAX;
        for (int &i:nums)
            if (i<min_val)
                min_val=i;
        int ans=0;
        for (int &i:nums)
            ans+=i-min_val;
        return ans;
    }
};
