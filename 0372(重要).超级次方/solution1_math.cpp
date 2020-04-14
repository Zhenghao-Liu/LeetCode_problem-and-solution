/*
* 对于(a*b)%k==(a%k)(b%k)%k
* 而对于次方b来说
  假设b=[1,2,3,4] a^1234=a^4 * a^1230=a^4 * (a^123)^10
* 所以对于一个很大的数组，通过不断取末尾值得到left左边因子，右边因子right因为幂次还是很大可以再调用本身递归进行压缩
* 而对于普通的a^4这种幂次较小的则可以直接for走一遍
* 采用第2行的公式进行缩小
*/
class Solution {
private:
    const int base=1337;
public:
    int superPow(int a, vector<int>& b) {
        if (b.empty())
            return 1;
        if (a==0)
            return 0;
        int last=b.back();
        b.pop_back();
        int left=my_pow(a,last);
        int right=my_pow(superPow(a,b),10);
        return (left*right)%base;
    }
    int my_pow(int a,int n)
    {
        int ans=1;
        a%=base;
        for (int i=0;i<n;++i)
        {
            ans*=a;
            ans%=base;
        }
        return ans;
    }
};
