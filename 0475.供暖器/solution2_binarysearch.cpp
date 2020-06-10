/**
* 线性自增移动太慢了
* 既然heaters已经排了序，那二分查找就可以了
* 这里的left意义也是当前房子右边距离最小的供暖器
*/
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        if (houses.empty())
            return 0;
        if (heaters.empty())
            return -1;
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int ans=0;
        int left=0;
        int heaters_size=heaters.size();
        for (int &i:houses)
        {
            int right=heaters_size-1;
            while (left<right)
            {
                int mid=left+(right-left)/2;
                if (heaters.at(mid)<i)
                    left=mid+1;
                else
                    right=mid;
            }
            if (left==0)
                ans=max(ans,distance(i,heaters.at(left)));
            else
                ans=max(ans,min(distance(i,heaters.at(left)),distance(i,heaters.at(left-1))));
        }
        return ans;
    }
    int distance(int a,int b)
    {
        return abs(a-b);
    }
};
