/*
 * A[a]~A[b]的区间和，是prefix[b+1]-prefix[a]
   即 j=b+1; i=a; 区间元素个数是 j-i
 * 有负数不能用滑窗,hack例子[-28,81,-20,28,-29] 89
 * 前缀和，即求prefix[j]-prefix[i]>=K
   当前处理的是j，存的是i
 * 维护一个单调递增给的单调队列
 */
typedef pair<int,int> pii;
class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int A_size=A.size();
        vector<int> prefix(A_size+1,0);
        int ans=INT_MAX;
        for (int i=0;i<A_size;++i)
            prefix.at(i+1)=prefix.at(i)+A.at(i);
        deque<int> deq;
        for (int i=0;i<=A_size;++i)
        {
            int cur=prefix.at(i);
            while (!deq.empty() && prefix.at(deq.back())>=cur )
                deq.pop_back();
            while (!deq.empty() && cur-prefix.at(deq.front())>=K)
            {
                ans=min(ans,i-deq.front());
                deq.pop_front();
            }
            deq.push_back(i);
        }
        return ans==INT_MAX ? -1 : ans;
    }
};
