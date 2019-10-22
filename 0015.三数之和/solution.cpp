static const auto SpeedUp = []{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {  
        vector <vector<int>> answer;
        int nums_size=nums.size();
        if(nums_size<=2)
            return answer;
        sort(nums.begin(), nums.end());
        int left=0,right=0;
        for (int index=0;index<nums_size;++index)
        {
            int index_value=nums.at(index);
            if (index_value>0)
                break;
            if (index!=0)
                if (nums.at(index)==nums.at(index-1))
                    continue;
            left=index+1;
            right=nums_size-1;
            while (left<right)
            {
                if (index_value+nums.at(left)+nums.at(right)<0)
                    ++left;
                else
                    if (index_value+nums.at(left)+nums.at(right)>0)
                        --right;
                    else
                    {
                        answer.push_back(vector<int>({index_value,nums.at(left),nums.at(right)}));
                        ++left;
                        --right;
                        while (nums.at(left)==nums.at(left-1) && nums.at(right)==nums.at(right+1) && left<right)
                        {
                            ++left;
                            --right;
                        }
                    }
            }
        }
        return answer;
    }
};
