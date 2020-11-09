/*
 * rand() % (b-a+1)+ a;就表示a~b之间的一个随机整数。
 */
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int size=points.size();
        helper(points,0,size-1,K-1);
        points.resize(K);
        return points;
    }
    void helper(vector<vector<int>>& points,int st,int ed,int tar)
    {
        if (st>=ed)
            return;
        int key_idx=rand()%(ed-st+1)+st;
        swap(points.at(st),points.at(key_idx));
        key_idx=st;
        vector<int> key=points.at(st);
        int key_value=key.at(0)*key.at(0)+key.at(1)*key.at(1);
        int l=st,r=ed;
        while (l<r)
        {
            while (l<r)
            {
                int v=points.at(r).at(0)*points.at(r).at(0)+points.at(r).at(1)*points.at(r).at(1);
                if (v<key_value)
                {
                    points.at(l)=points.at(r);
                    ++l;
                    break;
                }
                else
                    --r;
            }
            while (l<r)
            {
                int v=points.at(l).at(0)*points.at(l).at(0)+points.at(l).at(1)*points.at(l).at(1);
                if (v>key_value)
                {
                    points.at(r)=points.at(l);
                    --r;
                    break;
                }
                else
                    ++l;
            }
        }
        points.at(l)=key;
        if (l==tar)
            return;
        else if (l-1>=tar)
            helper(points,st,l-1,tar);
        else if (l+1<=tar)
            helper(points,l+1,ed,tar);
    }
};
