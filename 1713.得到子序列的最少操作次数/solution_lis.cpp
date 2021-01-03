/*
 * 因为target中每个元素是不同的，所以可以根据target中每个元素出现的顺序进行编号
 * 这样子编号后映射在arr中，如果arr中元素没有出现在target中说明没用，那么设为-1表示没用
 * 所以问题就转换成了在经过处理后的arr中，找到最长上升子序列
 * 这个子序列即是arr中的存在target元素的个数且是保证了在target中的相对顺序
   那么target.size-LIS.size就是答案
 * 看下复杂度1e5，所以用LIS的nlogn即二分方法来做
 */
class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        int t_size=target.size();
        unordered_map<int,int> ump;
        for (int i=0;i<t_size;i++) {
            ump[target.at(i)]=i;
        }
        for (int &i:arr) {
            if (ump.find(i)!=ump.end()) {
                i=ump.at(i);
            } else {
                i=-1;
            }
        }
        vector<int> lis;
        lis.reserve(t_size);
        for (int i:arr) {
            if (i==-1) {
                continue;
            }
            auto p=lower_bound(lis.begin(),lis.end(),i);
            if (p==lis.end()) {
                lis.push_back(i);
            } else {
                *p=i;
            }
        }
        return t_size-(int)lis.size();
    }
};
