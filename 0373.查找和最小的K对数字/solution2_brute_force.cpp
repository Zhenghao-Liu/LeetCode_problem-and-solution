struct cmp{
    bool operator()(const pair<int,int> &A,const pair<int,int> &B)
    {
        return (A.first+A.second)<(B.first+B.second);
    }
};
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> helper;
        for (int &i:nums1)
            for (int &j:nums2)
            {
                helper.push(make_pair(i,j));
                if (helper.size()>k)
                    helper.pop();
            }
        vector<vector<int>> ans;
        ans.reserve(k);
        while (!helper.empty())
        {
            auto [x,y]=helper.top();
            helper.pop();
            ans.push_back({x,y});
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
