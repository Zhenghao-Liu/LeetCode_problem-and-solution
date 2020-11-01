//根据值排序后，下标即是有多少个数比它小
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int nums_size=nums.size();
        vector<int> idx;
        idx.reserve(nums_size);
        for (int i=0;i<nums_size;++i)
            idx.push_back(i);
        sort(idx.begin(),idx.end(),[&nums](const int &A,const int &B){
            return nums.at(A)<nums.at(B);
        });
        vector<int> ans(nums_size);
        for (int i=0;i<nums_size;++i)
        {
            int cur=idx.at(i);
            if (i-1>=0)
            {
                int prev=idx.at(i-1);
                if (nums.at(cur)==nums.at(prev))
                {
                    ans.at(cur)=ans.at(prev);
                    continue;
                }
            }
            ans.at(cur)=i;
        }
        return ans;
    }
};
