/*
* 总共有N个元素
  b个黑名单，N-b个白名单
*/
class Solution {
    vector<int> black;
    int b;
    int N;
public:
    Solution(int _N, vector<int>& blacklist) {
        b=blacklist.size();
        N=_N;
        black=blacklist;
        sort(black.begin(),black.end());
    }
    
    int pick() {
        //代表求白名单中的第k个元素
        int k=rand()%(N-b);
        int l=0,r=b-1;
        while (l<r)
        {
            int mid=l+(r-l+1)/2;
            //求在mid左边的白名单元素有几个
            int less_mid_white=black.at(mid)-mid;
            if (less_mid_white>k)
                r=mid-1;
            else
                l=mid;
        }
        return l==r && black.at(l)-l<=k ? k+l+1 : k;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(N, blacklist);
 * int param_1 = obj->pick();
 */
