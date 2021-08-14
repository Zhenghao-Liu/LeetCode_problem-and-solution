class Solution {
public:
    int maxFrequency(vector<int>& nums, long long k) {
        sort(nums.begin(),nums.end());
        int l=0;
        long long cnt=0;
        int ans=1;
        int sz=nums.size();
        for (int i=1;i<sz;i++) {
            cnt+=(long long)(nums.at(i)-nums.at(i-1))*(i-l);
            while (cnt>k) {
                cnt-=nums.at(i)-nums.at(l);
                l++;
            }
            ans=max(ans,i-l+1);
        }
        return ans;
    }
};