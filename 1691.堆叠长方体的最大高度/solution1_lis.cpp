/**
 * 三维LIS
 * 那么怎么判断哪条边对哪条边
 * 显然是最大的边对最大的边，第二大的边对第二的边，第三大的边对第三大的边
   所以先内部排序，又因为要高最大，所以按升序排序
   再对外部整体排序
 * 采用n^2做法的LIS即可
 */
class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        for (vector<int> &i:cuboids)
            sort(i.begin(),i.end());
        sort(cuboids.begin(),cuboids.end());
        int ans=cuboids.at(0).at(2);
        int size=cuboids.size();
        vector<int> dp(size,0);
        dp.at(0)=cuboids.at(0).at(2);
        for (int i=1;i<size;++i) {
            int x=cuboids.at(i).at(0);
            int y=cuboids.at(i).at(1);
            int z=cuboids.at(i).at(2);
            dp.at(i)=z;
            for (int j=0;j<i;++j) {
                int px=cuboids.at(j).at(0);
                int py=cuboids.at(j).at(1);
                int pz=cuboids.at(j).at(2);
                if (x>=px && y>=py && z>=pz) {
                    dp.at(i)=max(dp.at(i),dp.at(j)+z);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};
