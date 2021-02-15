// 就只有两种情况，要么以0开头，要么以1开头
char flag[2]={'0','1'};
class Solution {
public:
    int minOperations(string s) {
        return min(solve(s,0),solve(s,1));
    }
    int solve(string &s,int idx) {
        int ans=0;
        for (char i:s) {
            if (i!=flag[idx]) {
                ans++;
            }
            idx^=1;
        }
        return ans;
    }
};
