//暴力，缓存石头和k的情况即可大量剪枝
class Solution {
    unordered_set<int> pos;
    vector<int> power{-1,0,1};
    //key是石头，value是k的多种情况
    unordered_map<int,unordered_set<int>> cache;
public:
    bool canCross(vector<int>& stones) {
        pos.clear();
        cache.clear();
        int stones_size=stones.size();
        for (int &i:stones)
        {
            pos.insert(i);
            cache.insert({i,{}});
        }
        return dfs(0,0,stones.back());
    }
    bool dfs(int cur_stone,int k,int target)
    {
        if (cur_stone==target)
            return true;
        if (cache.at(cur_stone).find(k)!=cache.at(cur_stone).end())
            return false;
        cache.at(cur_stone).insert(k);
        bool judge=false;
        for (int &i:power)
            if (k+i>0 && pos.find(cur_stone+k+i)!=pos.end())
            {
                judge=dfs(cur_stone+k+i,k+i,target) || judge;
                if (judge)
                    return true;
            }
        return judge;
    }
};
