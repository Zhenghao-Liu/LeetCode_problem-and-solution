/*
 * 题目问的是[恰好有k个不同数字的子数组的个数]
   不能直接滑窗去一扩一缩，暴力又n2，所以要转变一下
 * 转变成
   1. 最多有k个不同数字的子数组个数
   * 等于=有1个不同数字的子数组 + 有2个不同数字的子数组 + ··· + 有k-1个不同数字的子数组 + 有k个不同数字的子数组
   2. 最多有k-1个不同数字的子数组个数
   * 等于=有1个不同数字的子数组 + 有2个不同数字的子数组 + ··· + 有k-1个不同数字的子数组
   3. 恰好有k个不同数字的子数组的个数=最多有k个不同数字的子数组个数-最多有k-1个不同数字的子数组个数
 * 最多的问题即可以用滑窗扫一趟
 */
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        return solve(A,K)-solve(A,K-1);
    }
    int solve(vector<int> &A,int k) {
        if (k==0) {
            return 0;
        }
        int sz=A.size();
        vector<int> cnt(sz+1);
        int num=0;
        int l=0,r=0;
        int ans=0;
        while (r<sz) {
            if (cnt.at(A.at(r))==0) {
                num++;
            }
            cnt.at(A.at(r))++;
            r++;
            while (num>k) {
                cnt.at(A.at(l))--;
                if (cnt.at(A.at(l))==0) {
                    num--;
                }
                l++;
            }
            ans+=r-l;
        }
        return ans;
    }
};
