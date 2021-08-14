class Solution {
public:
    int getLucky(string s, int k) {
        int cnt=0;
        for (char i:s) {
            int num=i-'a'+1;
            while (num>0) {
                cnt+=num%10;
                num/=10;
            }
        }
        while (k>1) {
            int res=cnt;
            cnt=0;
            while (res>0) {
                cnt+=res%10;
                res/=10;
            }
            k--;
        }
        return cnt;
    }
};