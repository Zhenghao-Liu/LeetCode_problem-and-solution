/*
 * 看数据量是m*n=1e5
 * 所以nlogn是可以的
 * 把二维矩阵一行一行来看待，之后排序枚举：以当前行为底的话，最大子矩阵面积
 */
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& mat) {
        int row=mat.size();
        int col=mat.at(0).size();
        vector<int> vec(col);
        for (int i=0;i<col;i++) {
            vec.at(i)=i;
        }
        int ans=0;
        for (int i=0;i<row;i++) {
            if (i>0) {
                for (int j=0;j<col;j++) {
                    if (mat.at(i).at(j)!=0) {
                        mat.at(i).at(j)+=mat.at(i-1).at(j);
                    }
                }
            }
            sort(vec.begin(),vec.end(),[i,&mat](const int &A,const int &B){
                return mat.at(i).at(A)>mat.at(i).at(B);
            });
            int h=INT_MAX;
            for (int j=0;j<col;j++) {
                h=min(h,mat.at(i).at(vec.at(j)));
                ans=max(ans,h*(j+1));
            }
        }
        return ans;
    }
};
