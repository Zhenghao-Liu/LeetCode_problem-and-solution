//其实就是[378.有序矩阵中的第k小的元素]
class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int left=1*1,right=m*n;
        while (left<right)
        {
            int mid=left+(right-left)/2;
            int count=0;
            for (int i=1;i<=m;++i)
                count+=min(n,mid/i);
            if (count<k)
                left=mid+1;
            else
                right=mid;
        }
        return left;
    }
};
