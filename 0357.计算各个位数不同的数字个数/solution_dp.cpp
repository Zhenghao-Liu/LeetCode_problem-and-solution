/*
* 假设一个数字abcd
  要想不重复我们分开来讨论
* 当a=0时，其实就是bcde的情况，即dp.at(i-1)
* 当a!=0时，对于a取值有1~9共9种可能
  对于b可以取0~9，但是a已经从1~9中取了一个，所以b只能取9种情况
  对于c可以取0~9，但是ab已经各从0~9取了两个不重复的数字，所以c只能取8种情况
  对于d可与取0~9，但是abc已经各从0~9取了三个不重复的数字，所以d只能取7种情况
* 所以对于abcd来说 答案是 [bcd]+9*9*8*7
* 对于n位数字来说 答案是 [n-1]+9*9*8*7*···
                             取决于n位有多大，就有多少个因数
  而边界条件就是n=1时候，这时候数字只有0一个，即[1]=1
*/
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int> dp(n+1);
        dp.at(0)=1;
        //用factor表示下一个数字可用情况又多少个
        int factor=9;
        //用product缓存了之前的乘积
        int product=9;
        for (int i=1;i<=n;++i)
        {
            dp.at(i)=dp.at(i-1)+product;
            product*=factor;
            --factor;
        }
        return dp.at(n);
    }
};
