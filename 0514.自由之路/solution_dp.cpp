/*
* 因为length最大100，所以可以N^3做法
* 因为对于ring每次转之后必须是对应key中的字母
  且ring中可能有多个字母是相同的
* 做法：通过枚举key中匹配key[i]时，ring中12:00方向对应字母匹配key[i]的最小步数，
  正是因为ring中可能有重复字母匹配key[i]则所有情况都要都枚举到
* 旋转ring从索引i到j，因为有顺时针逆时针方向
  则选取最短即min(abs(j-i),ring_size-abs(j-i))，加上按下中心按钮这个步骤+1
** dp[j]则表示在ring中ring[j]匹配对应的key[i]时所需要的最小步数
* 且因为key[i-1]是唯一的字符，所以dp[j]之前就是匹配key[i-1]的最小步数
* 可以压缩成两行dp，
  状态方程：设index of key[i-1]为k
  dp[j]=min(dp[j],last_dp[k]+min(abs(k-j),ring_size-abs(k-j))+1)
* 注意初始化情况时last_dp无意义(都没第一行怎么会有前一行)即可
* 因为也有可能最后key.back()在ring中有多个匹配所以最后只需返回dp中的最小值即可
*/
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        if (key.empty() || ring.empty())
            return 0;
        int ring_size=ring.size();
        int key_size=key.size();
        vector<vector<int>> pos(26);
        //因为ring中可能有相同的字母，所以用数组记录下标
        for (int i=0;i<ring_size;++i)
            pos.at(ring.at(i)-'a').push_back(i);
        vector<int> last_dp(ring_size,INT_MAX);
        vector<int> dp(ring_size,INT_MAX);
        //初始化第一行：起点是index=0，终点是i，匹配的是key[0]
        for (int i:pos.at(key.at(0)-'a'))
            dp.at(i)=min(dp.at(i),min(abs(i-0),ring_size-abs(i-0))+1);
        for (int i=1;i<key_size;++i)
        {
            //滚动数组
            for (int j=0;j<ring_size;++j)
                last_dp.at(j)=dp.at(j);
            fill(dp.begin(),dp.end(),INT_MAX);
            //j表示ring匹配key[i]的所有索引
            //last_dp[k]!=INT_MAX表示匹配key[i-1]时ring中所有索引的情况
            for (int j:pos.at(key.at(i)-'a'))
                for (int k=0;k<ring_size;++k)
                    if (last_dp.at(k)!=INT_MAX)
                    {
                        int t=abs(j-k);
                        dp.at(j)=min(dp.at(j),last_dp.at(k)+min(t,ring_size-t)+1);
                    }
        }
        return *min_element(dp.begin(),dp.end());
    }
};
