class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> ump;
        for (int i:nums)
            if (i<k)
                ++ump[i];
        int ans=0;
        for (auto &i:ump)
        {
            int cur=i.first;
            int tar=k-cur;
            if (tar==cur)
            {
                int mi=i.second/2;
                i.second-=mi;
                ans+=mi;
                continue;
            }
            auto p=ump.find(tar);
            if (p!=ump.end())
            {
                int mi=min(i.second,(*p).second);
                ans+=mi;
                i.second-=mi;
                (*p).second-=mi;
            }
        }
        return ans;
    }
};
