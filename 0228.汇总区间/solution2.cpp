class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int nums_size=nums.size();
        if (nums_size==0)
            return {};
        vector<vector<int>> ans;
        ans.push_back({nums.at(0),nums.at(0)});
        int index=0;
        for (int i=1;i<nums_size;++i)
            if (nums.at(i)-1!=ans.at(index).at(1))
            {
                ans.push_back({nums.at(i),nums.at(i)});
                ++index;
            }
            else
                ans.at(index).at(1)=nums.at(i);
        vector<string> answer;
        for (vector<int>& i:ans)
            if (i.at(0)==i.at(1))
                answer.push_back(to_string(i.at(0)));
            else
                answer.push_back(to_string(i.at(0))+"->"+to_string(i.at(1)));
        return answer;
    }
};
