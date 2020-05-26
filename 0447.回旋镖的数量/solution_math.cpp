class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int points_size=points.size();
        //first存距离的平方
        //second存距离出现的次数
        unordered_map<int,int> count;
        int ans=0;
        for (int i=0;i<points_size;++i)
        {
            count.clear();
            int x=points.at(i).at(0);
            int y=points.at(i).at(1);
            for (int j=0;j<points_size;++j)
            {
                if (j==i)
                    continue;
                int xx=points.at(j).at(0);
                int yy=points.at(j).at(1);
                int distance=(xx-x)*(xx-x)+(yy-y)*(yy-y);
                ++count[distance];
            }
            for (auto &k:count)
                if (k.second>=2)
                    ans+=k.second*(k.second-1);
        }
        return ans;
    }
};
