//二分法搜索，注意溢出
class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num<2 || num==2147395600)
            return true;
        if (num>2147395600)
            return false;
        int left=1,right=num>>1;
        while (left<=right)
        {
            long long mid=left+((right-left)>>1);
            long long result=mid*mid;
            if (result==num)
                return true;
            else if (result>num)
                right=mid-1;
            else if (result<num)
                left=mid+1;
        }
        return false;
    }
};
