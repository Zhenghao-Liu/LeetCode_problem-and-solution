/*
* 对于si他的长度是2^i-1即(1<<i)-1;
* 以下标1开始，那么mid中间的'1'的下标就是length/2+1
* 倘若k就是mid那么就是直接'1'
* 倘若k<mid，表明是在si-1中求第k个字符，因为mid以及mid右边的字符都没有任何意义，可以递归
* 倘若k>mid，右半部分是由si-1先按位取反，再翻转得到的，所以要通过si求si-1则需要反过来操作
  先翻转，再按位取反
*/
class Solution {
public:
    char findKthBit(int n, int k) {
        int length=(1<<n)-1;
        return dfs(length,k);
    }
    char dfs(int length,int k)
    {
        if (length==1)
            return '0';
        int mid=length/2+1;
        if (mid==k)
            return '1';
        else if (k<mid)
            return dfs(mid-1,k);
        else
        {
            char ans=dfs(mid-1,length-k+1);
            return ans=='1' ? '0' : '1';
        }
        return -1;
    }
};
