/*
 * dp[i]表示考虑[0]~[i]名球员，且必定选择第[i]名球员时的最大分数
 * 要先按照年龄和成绩升序排序
 * 这样子从前往后遍历时，前面的年龄必然<=当前年龄
   1. 若是小于，只需要比较前面的成绩是否<=当前成绩，就可以转移
   2. 若是等于，因为还按照成绩升序排序，所以前面的成绩必然<=当前成绩，也可以转移
 * 初始化，即只选当前球员
 * 这样子最终答案因为至少要选1名球员
   即dp[0]~dp[i]中的最大值
 */
typedef pair<int,int> pii;
class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int size=scores.size();
        vector<pii> vec;
        vec.reserve(size);
        for (int i=0;i<size;++i)
            vec.push_back({ages.at(i),scores.at(i)});
        sort(vec.begin(),vec.end());
        vector<int> dp(size);
        for (int i=0;i<size;++i)
        {
            int cur_score=vec.at(i).second;
            dp.at(i)=cur_score;
            for (int j=0;j<i;++j)
                if (vec.at(j).second<=cur_score)
                    dp.at(i)=max(dp.at(i),dp.at(j)+cur_score);
        }
        return *max_element(dp.begin(),dp.end());
    }
};
