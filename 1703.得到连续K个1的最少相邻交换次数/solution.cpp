class Solution {
public:
    int minMoves(vector<int>& nums, int k) {
        int nums_size=nums.size();
        vector<int> bk;
        bk.reserve(nums_size);
        vector<int> prefix;
        prefix.reserve(nums_size+1);
        prefix.push_back(0);
        int idx=0;
        for (int i=0;i<nums_size;i++) {
            if (nums.at(i)==1) {
                int s_bk=i-idx+1;
                bk.push_back(s_bk);
                prefix.push_back(prefix.back()+s_bk);
                idx++;
            }
        }
        int ans=INT_MAX;
        int bk_size=bk.size();
        for (int l=0,r=k-1;r<bk_size;++l,++r) {
            int mid=(l+r)/2;
            int x=bk.at(mid);
            // 左半部分比中位数x要小，是[l~mid-1]
            int left_steps=(mid-1-l+1)*x-(prefix.at(mid-1+1)-prefix.at(l));
            // 右半部分比中位数x要大，是[mid+1~r]
            int right_steps=(prefix.at(r+1)-prefix.at(mid+1))-(r-(mid+1)+1)*x;
            ans=min(ans,left_steps+right_steps);
        }
        return ans;
    }
};
