//因为数是[0~N-1]且不相同，所以判断区间最大值是否是其下标相等就可判断是否可以切割
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int mx=0;
        int size=arr.size();
        int ans=0;
        for (int i=0;i<size;++i)
        {
            mx=max(mx,arr.at(i));
            if (mx==i)
                ++ans;
        }
        return ans;
    }
};
