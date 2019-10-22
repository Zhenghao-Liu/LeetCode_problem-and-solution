static const auto SpeedUp = []{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size_v=nums.size();
        for(int i=0;i<size_v;++i)
            for (int j=i+1;j<size_v;++j)
                if ((nums[i]+nums[j])==target)
                {
                    vector<int> answer_v({i,j});
                    return answer_v;
                }
        return nums;
    }
};
