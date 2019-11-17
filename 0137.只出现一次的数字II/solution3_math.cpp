class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> nums_set;
        double sum=0;
        for (int i:nums)
        {
            sum=sum+i;
            nums_set.insert(i);
        }
        double sum_set=0;
        for (int i:nums_set)
            sum_set=sum_set+i;
        return (3*sum_set-sum)/2;
    }
};
