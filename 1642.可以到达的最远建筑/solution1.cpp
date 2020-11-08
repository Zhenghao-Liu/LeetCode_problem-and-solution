//大顶堆，堆里面存已经用过的砖块数
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int size=heights.size();
        priority_queue<int,vector<int>,less<int>> pq;
        int i=0;
        for (i=0;i<size-1;++i)
        {
            int tar=heights.at(i+1)-heights.at(i);
            if (tar<=0)
                continue;
            else if (bricks>=tar)
            {
                pq.push(tar);
                bricks-=tar;
            }
            else if (ladders>0)
            {
                if (!pq.empty())
                {
                    if (tar>=pq.top())
                        --ladders;
                    else
                    {
                        bricks+=pq.top();
                        bricks-=tar;
                        pq.pop();
                        --ladders;
                        pq.push(tar);
                    }
                }
                else
                {
                    --ladders;
                }
            }
            else
                break;
        }
        return i;
    }
};
