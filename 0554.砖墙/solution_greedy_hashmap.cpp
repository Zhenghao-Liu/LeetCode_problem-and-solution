/*
* 一开始是想着按宽度枚举
  但是[[3]]这种我从1、2穿过去都是穿一块砖头，结果都是一样的
* 不如用前缀和方式记录下每一行，砖块的边缘出现的次数
  eg[[1,2,2,1]]即是1、3、5出现次数为1
  因为一行不可能有重复砖块边缘，所以每一行之间统计是不影响的
* 只要从出现最多次的砖块边缘穿过（贪心），就能越少的穿过砖
*/
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int,int> count;
        for (vector<int> &i:wall)
        {
            int prefix=0;
            int size=i.size();
            for (int j=0;j<size-1;++j)
            {
                prefix+=i.at(j);
                ++count[prefix];
            }
        }
        int ans=0;
        for (auto &i:count)
            if (i.second>ans)
                ans=i.second;
        return (int)wall.size()-ans;
    }
};
