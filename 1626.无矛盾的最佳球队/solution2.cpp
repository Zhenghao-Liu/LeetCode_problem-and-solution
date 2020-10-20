/*
 * dp[i]表示考虑[0]~[i]名球员，且必定选择第[i]名球员时的最大分数
 * 还可以按照成绩和年龄升序排序
 * 这样子从前往后遍历时，前面的成绩必然<=当前成绩
   1. 前面成绩<当前成绩情况，则需要找前面年龄<=当前年龄的
   2. 成绩=情况，不在乎年龄，但是因为按照了年龄升序排序，所以必然也符合前面年龄<=当前年龄的条件
 * 这样子最终答案因为至少要选1名球员
   即dp[0]~dp[i]中的最大值
 */
typedef pair<int,int> pii;
class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int size=scores.size();
        vector<pii> vec;
        vec.reserve(size+1);
        for (int i=0;i<size;++i)
            vec.push_back({scores.at(i),ages.at(i)});
        sort(vec.begin(),vec.end());
        vector<int> dp(size);
        for (int i=0;i<size;++i)
        {
            dp.at(i)=vec.at(i).first;
            int cur_age=vec.at(i).second;
            for (int j=0;j<i;++j)
                if (vec.at(j).second<=cur_age)
                    dp.at(i)=max(dp.at(i),dp.at(j)+vec.at(i).first);
        }
        return *max_element(dp.begin(),dp.end());
    }
};
