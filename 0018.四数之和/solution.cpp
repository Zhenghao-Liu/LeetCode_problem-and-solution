static const auto SpeedUp = []{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int nums_size=nums.size();
        vector<vector<int>> answer;
        if (nums_size<4)
            return answer;
        int left,right,index_value;
        for (int i=0;i<nums_size-3;++i)
        {
            if (i!=0 && nums.at(i)==nums.at(i-1))
                continue;
            for (int j=i+1;j<nums_size-2;++j)
            {
                if (j>i+1 && nums.at(j)==nums.at(j-1))
                    continue;
                left=j+1;
                right=nums_size-1;
                while (left<right)
                {
                    index_value=nums.at(i)+nums.at(j)+nums.at(left)+nums.at(right);
                    if (index_value>target)
                    {
                        --right;
                        while (left<right && nums.at(right)==nums.at(right+1))
                            --right;
                    }
                    else if (index_value<target)
                    {
                        ++left;
                        while (left<right && nums.at(left)==nums.at(left-1))
                            ++left;
                    }
                    else
                    {
                        answer.push_back(vector<int>({nums.at(i),nums.at(j),nums.at(left),nums.at(right)}));
                        ++left;
                        while (left<right && nums.at(left)==nums.at(left-1))
                            ++left;
                        --right;
                        while (left<right && nums.at(right)==nums.at(right+1))
                            --right;
                    }       
                }             
            }
        }
        return answer;
    }
};
