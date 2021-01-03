//玩家属性必然是一个递增序列，那么就可以用二分查找，用关卡来二分查找最小的>=关卡的属性
class Solution {
public:
    vector<int> getTriggerTime(vector<vector<int>>& increase, vector<vector<int>>& requirements) {
        int increase_size=increase.size();
        vector<vector<int>> prfix{{0,0,0}};
        for (int i=0;i<increase_size;++i)
        {
            int prfix_c=prfix.at(i).at(0)+increase.at(i).at(0);
            int prfix_r=prfix.at(i).at(1)+increase.at(i).at(1);
            int prfix_o=prfix.at(i).at(2)+increase.at(i).at(2);
            prfix.push_back({prfix_c,prfix_r,prfix_o});
        }
        int requirements_size=requirements.size();
        vector<int> ans;
        for (vector<int> &i:requirements)
        {
            int left=0,right=increase_size;
            while (left<right)
            {
                int mid=left+((right-left)>>1);
                if (prfix.at(mid).at(0)>=i.at(0) && prfix.at(mid).at(1)>=i.at(1) && prfix.at(mid).at(2)>=i.at(2))
                    right=mid;
                else
                    left=mid+1;
            }
            if (prfix.at(left).at(0)>=i.at(0) && prfix.at(left).at(1)>=i.at(1) && prfix.at(left).at(2)>=i.at(2))
                ans.push_back(left);
            else
                ans.push_back(-1);
        }
        return ans;
    }
};
