/*
* 总共有N个元素
  [0,N-1]范围内设有blacklist.size()=b个黑名单
* 设在[0,N-b-1]长度为N-b的区间内，黑名单有x个
  那么在[N-b,N-1]长度为b的区间内，黑名单有b-x个，
  那么区间内剩下的就是白名单，即b-(b-x)=x个白名单
* 即[0,N-b-1]中的黑名单和[N-b,N-1]中的白名单是相等的，可以一一映射
*/
class Solution {
    unordered_map<int,int> b_to_w;
    int b;
    int N;
public:
    Solution(int _N, vector<int>& blacklist) {
        b=blacklist.size();
        N=_N;
        unordered_set<int> blacklist_set(blacklist.begin(),blacklist.end());
        int value=N-b;
        for (int i:blacklist)
            if (i<=N-b-1)
            {
                while (blacklist_set.find(value)!=blacklist_set.end())
                    ++value;
                b_to_w[i]=value;
                ++value;
            }
    }
    
    int pick() {
        int ans=rand()%(N-b);
        return b_to_w.find(ans)==b_to_w.end() ? ans : b_to_w.at(ans);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(N, blacklist);
 * int param_1 = obj->pick();
 */
