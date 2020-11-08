//小顶堆，堆的大小最大时梯子数量，这样堆里面一直是最大的砖块元素
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int,vector<int>,greater<int>> pq;
        int sum=0;
        int size=heights.size();
        for (int i=1;i<size;++i)
        {
            int diff=heights.at(i)-heights.at(i-1);
            if (diff>0)
            {
                pq.push(diff);
                if (pq.size()>ladders)
                {
                    sum+=pq.top();
                    pq.pop();
                    if (sum>bricks)
                        return i-1;
                }
            }
        }
        return size-1;
    }
};
