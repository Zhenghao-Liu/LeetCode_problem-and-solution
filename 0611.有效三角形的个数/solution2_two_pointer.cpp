/*
* i、j、k，符合i<=j<=k且三角形i+j>k
* 固定k，i在最小值，j在最大值
  倘若i+j>k，则表明j不同时，比i大的都满足ii+j>k，所以ans+=j-i，且讨论和更小的部分--j
  倘若i+j<=k，则表明i过于小了，所以++i
*/
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int ans=0;
        sort(nums.begin(),nums.end());
        int size=nums.size();
        for (int k=size-1;k>=2;--k)
        {
            int i=0,j=k-1;
            while (i<j)
            {
                if (nums.at(i)+nums.at(j)>nums.at(k))
                {
                    ans+=j-i;
                    --j;
                }
                else
                    ++i;
            }
        }
        return ans;
    }
};
