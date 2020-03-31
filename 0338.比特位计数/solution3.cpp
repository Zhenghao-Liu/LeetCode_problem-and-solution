/*
* 和方法2有点类似
* i&1其实是求i的最右边的是0还是1
* i>>1即不考虑最后一位时的结果
* 不考虑最后一位+最后一位=答案
*/
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num+1,0);
        for (int i=1;i<=num;++i)
            ans.at(i)=ans.at(i>>1)+(i&1);
        return ans;
    }
};
