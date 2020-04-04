class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mask;
        for (int &i:nums)
            ++mask[i];
        vector<pair<int,int>> sorted_mask;
        for (auto &i:mask)
            sorted_mask.push_back(make_pair(i.first,i.second));
        sort(sorted_mask.begin(),sorted_mask.end(),[](const pair<int,int> &A,const pair<int,int> &B){
            return A.second>B.second;
        });
        vector<int> ans;
        ans.reserve(k);
        for (int i=0;i<k;++i)
            ans.push_back(sorted_mask.at(i).first);
        return ans;
    }
};
