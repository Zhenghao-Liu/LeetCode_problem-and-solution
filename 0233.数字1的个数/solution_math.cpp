/*
* 对于一个连续的数字假设是xyzdabc
* 求个位为1的组合有多少个。求十位为1的组合有多少个。一直求到x这一位
* 假设只求d这一位（千位）为1的组合有多少个
* xyz取值有0~xyz，由于d不知道数字是多少(如果d是0那么xyz不能取xyz这个值，假设xyz=2,d=0,abc=0,200没有1，只有110才有1)，所以我们先讨论0~xyz-1的情况
  xyz取0~xyz-1共xyz种情况 而对于abc来说因为这里前面最大是xyz-1了即abc是可以从000~999种的共1000种 即xyz*1000种
* 现在来讨论xyz取xyz的情况了这里就要对d来讨论
* d为0的话，xyz取xyz abc随便取都组合不到千位为1的数字
           总和xyz*1000
* d为1的话，在原来基础xyz*1000基础上，xyz取xyz 即数字xyz1abc，abc可以取0~abc即abc+1种情况，即xyz取xyz时共有1*（abc+1）种可能性
           总和xyz*1000+abc+1
* d为大于1的情况，就代表原来xyz*1000基础上，xyz取xyz，即数字xyz1abc，abc可以取0~999共1000种情况了，因为xyz2000增大也实现不了千位为1了，
           总和xyz*1000+1000
* 例子是求了千位为1的情况，那就对数字所有位都求一次即可
*/
class Solution {
public:
    int countDigitOne(int n) {
        int ans=0;
        int xyz=n;
        for (long i=1;i<=n;i*=10)
        {
            int d=xyz%10;
            xyz/=10;
            int abc=n%i;
            ans+=xyz*i;
            if (d==1)
                ans+=abc+1;
            else if (d>1)
                ans+=i;
        }
        return ans;
    }
};
