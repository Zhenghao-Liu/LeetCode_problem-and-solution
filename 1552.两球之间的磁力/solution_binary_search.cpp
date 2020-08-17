/*
* 首先对pos升序排序
* 然后去二分最终的答案
* 最小的最大、最大的最小一般是二分的关键词
*/
class Solution {
public:
    int maxDistance(vector<int>& pos, int m) {
        sort(pos.begin(),pos.end());
        if (m==2)
            return pos.back()-pos.at(0);
        int l=1,r=pos.back()-pos.at(0);
        int size=pos.size();
        while (l<r)
        {
            int mid=l+(r-l+1)/2;
            int ans=1;
            int cur=pos.at(0);
            for (int i=1;i<size;++i)
            {
                if (pos.at(i)-cur>=mid)
                {
                    ++ans;
                    cur=pos.at(i);
                }
            }
            if (ans>=m)
                l=mid;
            else
                r=mid-1;
        }
        return l;
    }
};
