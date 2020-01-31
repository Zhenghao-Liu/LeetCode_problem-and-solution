// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left=1,right=n,answer=0;
        int mid;
        while (left<=right)
        {
            //原版是mid=(left+right)/2;这题测试数据比较大
            //还可以改成double mid=(left*1.0+right*1.0)/2;
            mid=left+(right-left)/2;
            if (isBadVersion(mid))
            {
                answer=mid;
                right=mid-1;
            }
            else
                left=mid+1;
        }
        return answer;
    }
};
