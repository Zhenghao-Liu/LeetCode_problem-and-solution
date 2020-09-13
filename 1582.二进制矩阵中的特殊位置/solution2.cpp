/*
* 因为是整形数组，且0-1矩阵，可以缓存每一行每一列的和
* 之后判断一个元素是不是1，且所在行的元素和和所在列的元素和是不是都是1即可
*/
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int r=mat.size();
        int c=mat.at(0).size();
        vector<int> r_cnt(r);
        vector<int> c_cnt(c);
        for (int i=0;i<r;++i)
            for (int j=0;j<c;++j)
            {
                c_cnt.at(j)+=mat.at(i).at(j);
                r_cnt.at(i)+=mat.at(i).at(j);
            }
        int ans=0;
        for (int i=0;i<r;++i)
            for (int j=0;j<c;++j)
                if (mat.at(i).at(j)==1 && r_cnt.at(i)==1 && c_cnt.at(j)==1)
                    ++ans;
        return ans;
    }
};
