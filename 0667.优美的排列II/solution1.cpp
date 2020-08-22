//下标从[0, k]中，偶数下标填充[1,2,3…]，奇数下标填充[k + 1, k, k - 1…]
//后面[k + 1, n - 1]都是顺序填充索引值+1
class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans(n);
        int num=1;
        for (int i=0;i<=k;i+=2)
        {
            ans.at(i)=num;
            ++num;
        }
        num=k+1;
        for (int i=1;i<=k;i+=2)
        {
            ans.at(i)=num;
            --num;
        }
        for (int i=k+1;i<n;++i)
            ans.at(i)=i+1;
        return ans;
    }
};
