class Solution {
public:
    int minJump(vector<int>& jump) {
        //把向左跳，移动到了向右跳之前
        int jump_size=jump.size();
        //dp[i]表示到位置i的最少弹射次数
        vector<int> dp(jump_size+1);
        //当前在位置i
        //情况一: j->i->i+jump[i],j>i ,右侧跳到i，i再往右走
        //反正右边有那么多种可能j，不妨找跳到j最少的次数那个位置，在那个位置左跳到i
        //那要找最小次数可以跳到的j位置，不妨用优先队列来存取j的可能性
        //情况二: i->i+jump[i] ,i直接往下一个位置跳
        //初始化最大可能性，用INT_MAX可能会越界哦
        for (int i=1;i<=jump_size;++i)
            dp.at(i)=jump_size;
        dp.at(0)=0;
        //优先队列中(x,y)表示按x次弹簧跳到y位置
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> que;
        for (int i=0;i<jump_size;++i)
        {
            //倘若队列中有的j是位于i的左边的即j<=i则无讨论意义
            while (!que.empty() && que.top().second<=i)
                que.pop();
            //当前i按照向右跳的地方，因为最远就是n了即跳出机器
            int next_pos=min(jump_size,i+jump.at(i));
            //情况二跳到下一个右边的按弹簧次数
            int cost=dp.at(i)+1;
            if (!que.empty())
                //按照情况一，从右边j跳到i，在i跳到下一个右边
                //而从情况一，j跳到i要一次弹簧，i跳到下一个右边要2次弹簧所以要加2
                cost=min(cost,que.top().first+2);
            //更新i跳到下一个右边这个位置的，需要到这个位置的最少弹簧次数
            if (cost<dp.at(next_pos))
            {
                dp.at(next_pos)=cost;
                que.push(make_pair(cost,next_pos));
            }
        }
        return dp.at(jump_size);
    }
};
