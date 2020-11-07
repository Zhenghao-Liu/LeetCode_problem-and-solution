const int MAXN=201;
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int cnt[MAXN];
        memset(cnt,0,sizeof(cnt));
        for (int i:nums)
            ++cnt[i+100];
        sort(nums.begin(),nums.end(),[&cnt](const int &A,const int &B){
            return cnt[A+100]==cnt[B+100] ? A>B : cnt[A+100]<cnt[B+100];});
        return nums;
    }
};
