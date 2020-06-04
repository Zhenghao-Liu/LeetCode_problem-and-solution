class Solution {
    //因为拿2再拿3，和拿3再拿2，是一种情况，所以缓存
    unordered_map<int,bool> cache; 
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger>=desiredTotal)
            return true;
        if (maxChoosableInteger*(maxChoosableInteger+1)/2<desiredTotal)
            return false;
        //开辟多了个无用的0，因为取数字不能取0，方便操作
        //用[i]=0代表没有被使用，用[i]=1代表已经使用了
        //再将uses来作为cache的key
        //可以转成string，或者采用位运算转成int，这里转成int
        vector<int> uses(maxChoosableInteger+1,0);
        cache.clear();
        return dfs(uses,maxChoosableInteger,desiredTotal);
    }
    bool dfs(vector<int> & uses,const int & maxChoosableInteger,int desiredTotal)
    {
        int key=0;
        for (int i=1;i<=maxChoosableInteger;++i)
        {
            key<<=1;
            key|=uses.at(i);
        }
        if (cache.find(key)!=cache.end())
            return cache.at(key);
        for (int i=1;i<=maxChoosableInteger;++i)
        {
            if (uses.at(i)==0)
            {
                uses.at(i)=1;
                //情况一：当前可选数字直接超过目标累积和，则直接胜利
                //情况二：我拿了这个数字后，对方输了，那说明我赢了
                if (i>=desiredTotal || !dfs(uses,maxChoosableInteger,desiredTotal-i))
                {
                    //这里缓存的还是一开始key，不是key与上i
                    //因为cache存的是在某一状态下(已经取了部分数字)，一个人开始，是必胜还是必败
                    cache.insert({key,true});
                    //回溯
                    uses.at(i)=0;
                    return true;
                }
                uses.at(i)=0;
            }
        }
        cache.insert({key,false});
        return false;
    }
};
