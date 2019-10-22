static const auto SpeedUp = []{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int nums_size=nums.size();
        int answer=nums.at(0)+nums.at(1)+nums.at(2);
        int left=0,right=nums_size-1,index_total_value=0;
        for (int index=0;index<nums_size-2;++index)
        {
            left=index+1;
            right=nums_size-1;
            while (left<right)
            {
                index_total_value=nums.at(index)+nums.at(left)+nums.at(right);
                if ( abs(target-index_total_value) < abs(target-answer) )
                    answer=index_total_value;
                if (index_total_value>target)
                    --right;
                else if (index_total_value<target)
                    ++left;
                else
                    return target;
            }  
        }
        return answer;
    }
};
