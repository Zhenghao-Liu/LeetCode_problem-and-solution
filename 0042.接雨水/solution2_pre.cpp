//提前预存好对于柱子i来说，左边最高的柱子高是多少，右边最高的柱子高是多少，就不用再向左右去搜索高度了
class Solution {
public:
    int trap(vector<int>& height) {
        int height_size=height.size();
        vector<int> left(height_size,0);
        for (int i=1;i<height_size-1;++i)
            left.at(i)=max(left.at(i-1),height.at(i-1));
        vector<int> right(height_size,0);
        for (int i=height_size-2;i>0;--i)
            right.at(i)=max(right.at(i+1),height.at(i+1));
        int ans=0;
        for (int i=1;i<height_size-1;++i)
        {
            int min_height=min(left.at(i),right.at(i));
            if (min_height>height.at(i))
                ans+=min_height-height.at(i);
        }
        return ans;
    }
};
