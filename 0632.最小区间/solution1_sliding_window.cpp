//一个区间要至少包含k个列表的一个数，那么把列表的元素整合成一个数组，然后标识每个元素来自那个列表，然后滑窗即可
typedef pair<int,int> pii;
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int nums_size=nums.size();
        int all_size=0;
        for (vector<int> &i:nums)
            all_size+=i.size();
        vector<pii> all;
        all.reserve(all_size);
        for (int i=0;i<nums_size;++i)
            for (int j:nums.at(i))
                all.push_back({j,i});
        sort(all.begin(),all.end(),[](const pii &A,const pii &B){
            return A.first<B.first;
        });
        vector<int> count(nums_size,0);
        int all_have=0;
        int right=0;
        int ans_left=-1e5,ans_right=1e5;
        for (int i=0;i<all_size;++i)
        {
            if (i>0)
            {
                --count.at(all.at(i-1).second);
                if (count.at(all.at(i-1).second)==0)
                    --all_have;
            }   
            while (right<all_size && all_have!=nums_size)
            {
                if (count.at(all.at(right).second)==0)
                    ++all_have;
                ++count.at(all.at(right).second);
                ++right;
            }
            if (all_have==nums_size)
            {
                int l=all.at(i).first;
                int r=all.at(right-1).first;
                if (r-l<ans_right-ans_left)
                {
                    ans_right=r;
                    ans_left=l;
                }
            }
            else
                return {ans_left,ans_right};
        }
        return {ans_left,ans_right};
    }
};
