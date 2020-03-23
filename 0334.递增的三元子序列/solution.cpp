/*
* 其实更关键的是找到递增三元子序列中第二个元素
* 因为是要找递增的序列，所以如果值更小的序列要更新索引
* 值倒数第二小的序列和最小的序列都可以和一个较大的数构成递增子序列，但值更小的索引更有可能，所以要更新
*/
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int min_num=INT_MAX,helper=INT_MAX;
        for (int &i:nums)
            if (i<min_num)
                min_num=i;
            else if (i<helper && i>min_num)
                helper=i;
            else if (i>helper)
                return true;
        return false;
    }
};
