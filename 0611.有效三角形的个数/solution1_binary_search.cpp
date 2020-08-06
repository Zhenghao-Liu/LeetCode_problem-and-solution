/*
* 设边i、j、k且i<=j<=k且要满足三角形即i+j>k
* 固定好i、j，剩下的数组是有序的，所以可以用二分查找符合的k有多少个
*/
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int ans=0;
        sort(nums.begin(),nums.end());
        int size=nums.size();
        for (int i=0;i<size-2;++i)
            for (int j=i+1;j<size-1;++j)
            {
                int left=j+1,right=size-1;
                int target=nums.at(i)+nums.at(j);
                while (left<=right)
                {
                    int mid=left+(right-left)/2;
                    if (nums.at(mid)>=target)
                        right=mid-1;
                    else
                        left=mid+1;
                }
                ans+=left-j-1;
            }
        return ans;
    }
};
