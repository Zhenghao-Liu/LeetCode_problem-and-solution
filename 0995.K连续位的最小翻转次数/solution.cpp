/*
 * 翻了n次的先后顺序不影响，最终结果是不变的
 * 如果一个数字是0，那么代表需要翻转
 * 我们可以从左往右遍历，遇到0就代表要翻转
 * 但是翻转操作是区间的，所以采用差分数组区间加形式来代表翻转
 * 如果不能翻转则-1
 */
class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int sz=A.size();
        vector<int> vec(sz);
        vec.at(0)=A.at(0);
        for (int i=1;i<sz;i++) {
            vec.at(i)=A.at(i)-A.at(i-1);
        }
        int ans=0;
        int cur=0;
        for (int i=0;i<sz;i++) {
            cur+=vec.at(i);
            if (cur%2==0) {
                ans++;
                int st=i,ed=i+K;
                vec.at(st)++;
                cur++;
                if (ed<sz) {
                    vec.at(ed)--;
                } else if (ed>sz) {
                    return -1;
                }
            }
        }
        return ans;
    }
};
