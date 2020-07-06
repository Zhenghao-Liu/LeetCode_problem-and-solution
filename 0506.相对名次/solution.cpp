typedef pair<int,int> pii;
vector<string> top_3{"Gold Medal","Silver Medal","Bronze Medal"};
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        int nums_size=nums.size();
        //first存奖牌数，second存在nums中的索引
        vector<pii> helper;
        helper.reserve(nums_size);
        for (int i=0;i<nums_size;++i)
            helper.push_back({nums.at(i),i});
        sort(helper.begin(),helper.end(),[](const pii &A,const pii &B){
            return A.first>B.first;
        });
        vector<string> ans(nums_size);
        for (int i=0;i<nums_size;++i)
        {
            if (i<3)
                ans.at(helper.at(i).second)=top_3.at(i);
            else
                ans.at(helper.at(i).second)=to_string(i+1);
        }
        return ans;
    }
};
