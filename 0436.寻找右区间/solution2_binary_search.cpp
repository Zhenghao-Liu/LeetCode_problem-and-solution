/*
* 增加一个原来数组的索引为[i][2]
* 进行按照[i][0]的升序排序和此基础上[i][2]升序
* 因为要找的是[j][0]>=[i][1]
* 且此时[j][0]已经排序了，所以二分查找就好了
*/
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int intervals_size=intervals.size();
        if (intervals_size==1)
            return {-1};
        for (int i=0;i<intervals_size;++i)
            intervals.at(i).push_back(i);
        sort(intervals.begin(),intervals.end(),[](const vector<int> &a,const vector<int> &b){
            return a.at(0)==b.at(0) ? a.at(2)<b.at(2) : a.at(0)<b.at(0);
        });
        vector<int> ans(intervals_size,-1);
        for (int i=0;i<intervals_size;++i)
        {
            int left=0,right=intervals_size;
            int target=intervals.at(i).at(1);
            while (left<right)
            {
                int mid=left+(right-left)/2;
                if (intervals.at(mid).at(0)>=target)
                    right=mid;
                else
                    left=mid+1;
            }
            if (left<intervals_size)
                ans.at(intervals.at(i).at(2))=intervals.at(left).at(2);
        }
        return ans;
    }
};
