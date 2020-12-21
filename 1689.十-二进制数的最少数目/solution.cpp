//脑经急转弯：要么是1要么是0，n上的一位数是几，最少就要几个1
class Solution {
public:
    int minPartitions(string n) {
        int ans=0;
        for (char i:n)
            if (i-'0'>ans)
                ans=i-'0';
        return ans;
    }
};
