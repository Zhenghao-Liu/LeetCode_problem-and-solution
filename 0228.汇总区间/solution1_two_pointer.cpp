class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int nums_size=nums.size();
        if (nums_size==0)
            return {};
        vector<string> answer;
        int left=nums.at(0),right=nums.at(0);
        for (int i=1;i<nums_size;++i)
        {
            if (nums.at(i)-1==right)
                right=nums.at(i);
            else
            {
                if (left==right)
                    answer.push_back(to_string(left));
                else
                    answer.push_back(to_string(left)+"->"+to_string(right));
                left=right=nums.at(i);
            }
        }
        if (left==right)
            answer.push_back(to_string(left));
        else
            answer.push_back(to_string(left)+"->"+to_string(right));
        return answer;
    }
};
