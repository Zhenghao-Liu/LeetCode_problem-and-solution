class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int row=matrix.size(),col=matrix.at(0).size();
        int ans=0;
        vector<vector<int>> sum(row+1,vector<int>(col+1));
        for (int i=0;i<row;i++) {
            for (int j=0;j<col;j++) {
                sum.at(i+1).at(j+1)=
                    sum.at(i).at(j+1)+
                    sum.at(i+1).at(j)-
                    sum.at(i).at(j)+
                    matrix.at(i).at(j);
            }
        }
        unordered_map<int,int> ump;
        for (int up=0;up<row;up++) {
            for (int down=up;down<row;down++) {
                ump.clear();
                ump[0]++;
                for (int j=0;j<col;j++) {
                    //[up][0],[down][j]
                    int cur=
                        sum.at(down+1).at(j+1)-
                        sum.at(down+1).at(0)-
                        sum.at(up).at(j+1)+
                        sum.at(up).at(0);
                    auto p=ump.find(cur-target);
                    if (p!=ump.end()) {
                        ans+=p->second;
                    }
                    ump[cur]++;
                }
            }
        }
        return ans;
    }
};