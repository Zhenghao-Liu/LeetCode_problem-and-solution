class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger>=desiredTotal)
            return true;
        if (maxChoosableInteger*(maxChoosableInteger+1)/2<desiredTotal)
            return false;
        //每一个i表示使用过的状态
        //将i换成二进制表示，1b表示使用过0b表示使用过，1010则表示已经使用了2和4(最右边的第一位代表1)
        //将[i]表示以状态i开始的一个人，是必胜还是必败，1是胜，-1是败，0是未处理
        //maxChoosableInteger是几，那么就需要几位的二进制
        //eg:maxChoosableInteger=3，那么1<<3就是1000B即元素可以从000B~111B，虽然111B可能会提早退出用不到
        vector<int> uses_state(1<<maxChoosableInteger,0);
        return dfs(uses_state,maxChoosableInteger,desiredTotal,0);
    }
    bool dfs(vector<int> & uses_state,const int & maxChoosableInteger,int desiredTotal,int state)
    {
        if (uses_state.at(state)!=0)
            return uses_state.at(state)==1;
        for (int i=1;i<=maxChoosableInteger;++i)
        {
            int index=1<<(i-1);
            if ((state&index)==0)
            {
                int next_state=state|index;
                //情况一：当前可选数字直接超过目标累积和，则直接胜利
                //情况二：我拿了这个数字后，对方输了，那说明我赢了
                if (i>=desiredTotal || !dfs(uses_state,maxChoosableInteger,desiredTotal-i,next_state))
                {
                    uses_state.at(state)=1;
                    return true;
                }
            }
        }
        uses_state.at(state)=-1;
        return uses_state.at(state)==1;
    }
};
