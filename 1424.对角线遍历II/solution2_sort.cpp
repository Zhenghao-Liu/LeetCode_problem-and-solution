//每一斜的横坐标加纵坐标都是一样的，在一斜内再根据行的降序来排
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        //first=i+j
        //second=i
        vector<pair<int,int>> helper;
        int row=nums.size();
        for (int i=0;i<row;++i)
        {
            int column=nums.at(i).size();
            for (int j=0;j<column;++j)
                helper.push_back({i+j,i});
        }
        sort(helper.begin(),helper.end(),[](const pair<int,int> &A,const pair<int,int> &B){
            return A.first==B.first ? A.second>B.second : A.first<B.first;
        });
        vector<int> ans;
        ans.reserve(1e5);
        for (pair<int,int> &i:helper)
            ans.push_back(nums.at(i.second).at(i.first-i.second));
        return ans;
    }
};
