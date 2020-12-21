/*
 * 长方体的长宽高有6种排列组合全部枚举一遍，
   但为了dp时候检测到同一个长方体，所以再引入一个长方体的序号
 */
class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        vector<tuple<int,int,int,int>> vec;
        int size=cuboids.size();
        for (int i=0;i<size;i++) {
            const vector<int> &ii=cuboids.at(i);
            vec.push_back({ii.at(0),ii.at(1),ii.at(2),i});
            vec.push_back({ii.at(0),ii.at(2),ii.at(1),i});
            vec.push_back({ii.at(1),ii.at(0),ii.at(2),i});
            vec.push_back({ii.at(1),ii.at(2),ii.at(0),i});
            vec.push_back({ii.at(2),ii.at(0),ii.at(1),i});
            vec.push_back({ii.at(2),ii.at(1),ii.at(0),i});
        }
        sort(vec.begin(),vec.end());
        vector<int> dp(size*6);
        for (int i=0;i<size*6;i++) {
            auto [x,y,z,idx]=vec.at(i);
            dp.at(i)=z;
            for (int j=0;j<i;j++) {
                auto [px,py,pz,pidx]=vec.at(j);
                if (pidx!=idx && px<=x && py<=y && pz<=z) {
                    dp.at(i)=max(dp.at(i),dp.at(j)+z);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};
