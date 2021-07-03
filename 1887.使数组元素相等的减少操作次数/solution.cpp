class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        map<int,int> mp;
        for (int i:nums) {
            mp[i]++;
        }
        int ans=0;
        while (mp.size()>1) {
            auto p=mp.end();
            p--;
            int cnt=p->second;
            ans+=cnt;
            mp.erase(p);
            p=mp.end();
            p--;
            p->second+=cnt;
        }
        return ans;
    }
};