/*
若n=8初始状态
1 2 3 4 5 6 7 8
k=1          | 1 2 3 4 5 6 7 8 (不翻转，直接返回)
k=2          1 | 8 7 6 5 4 3 2
k=3          1 8 | 2 3 4 5 6 7
k=4          1 8 2 | 7 6 5 4 3
总结规律：当k>1时,需要翻转的次数为k-1次，每次翻转保留前m(m = 1,2,3...k-1)个数，每次翻转都在原数组进行。
*/
class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans(n);
        for (int i=1;i<=n;++i)
            ans.at(i-1)=i;
        int times=k-1;
        int start=1,end=n-1;
        while (times>0)
        {
            helper(ans,start,end);
            ++start;
            --times;
        }
        return ans;
    }
    void helper(vector<int> &ans,int start,int end)
    {
        while (start<end)
        {
            swap(ans.at(start),ans.at(end));
            ++start;
            --end;
        }
    }
};
