class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int size=M.size();
        vector<bool> visit(size,false);
        int ans=0;
        for (int i=0;i<size;++i)
            if (!visit.at(i))
            {
                ++ans;
                queue<int> helper;
                helper.push(i);
                while (!helper.empty())
                {
                    int cur=helper.front();
                    helper.pop();
                    for (int j=0;j<size;++j)
                        if (!visit.at(j) && M.at(cur).at(j)==1)
                        {
                            visit.at(j)=true;
                            helper.push(j);
                        }
                }
            }
        return ans;
    }
};
