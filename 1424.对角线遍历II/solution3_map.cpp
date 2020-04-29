class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int row=nums.size();
        //key=i+j;
        //value=一个斜线上[i][j]的值
        map<int,vector<int>> helper;
        //从最后一行开始遍历，就不用后面再reverse了
        for (int i=row-1;i>=0;--i)
        {
            int column=nums.at(i).size();
            for (int j=0;j<column;++j)
                helper[i+j].push_back(nums.at(i).at(j));
        }
        vector<int> ans;
        ans.reserve(1e5);
        for (auto &i:helper)
            for (int &j:i.second)
                ans.push_back(j);
        return ans;
    }
};
