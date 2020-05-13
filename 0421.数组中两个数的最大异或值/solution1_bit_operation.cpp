/**
* a^b=c
* 则可以推出a^c=b b^c=a
  推导  a^b=c
        a^b^b^c=c^b^c
        得a^c=b
* 本方法只能得出结果并不能得出是谁和是xor得到ans
* 在这我们设最后的答案max_xor就是c，而ai^aj=max_xor的两个数是a和b
* 要想异或结果是最大的，那一个数最大那当然是二进制下从左往右尽可能的填1
* 所以要先得到数组nums中的最大值看下二进制下是几位数，因为超过最大值位数的位置只能是0了
* 因为结果数字要想越大，越高位越大有好，所以循环从nums中数字的最高位开始处理
* 数字结果越大，那最好当然是1，所以我们用cur_try_max_xor来代表当前位数最优可能
  即当前处理位数为1
* 那么倘若集合中出现了某个数字a能够和cur_try_max_xor异或得到一个存在于集合中的数b
  即找到a^cur_try_max_xor=b的情况
  那么根据前面推理其实就满足了a^b=cur_try_max_xor，即当前最优cur_try_max_xor是可行的
*/
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int nums_size=nums.size();
        if (nums_size==0)
            return 0;
        int max_num=INT_MIN;
        for (int &i:nums)
            if (i>max_num)
                max_num=i;
        //__builtin_clz(max_num)用来求一个数前面有多少个前导0
        //[GCC内置函数](https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html?tdsourcetag=s_pctim_aiomsg)
        int max_num_length;
        if (max_num!=0)
            max_num_length=32-__builtin_clz(max_num);
        else
            max_num_length=1;
        int max_xor=0;
        int cur_try_max_xor=0;
        unordered_set<int> helper;
        for (int i=max_num_length-1;i>=0;--i)
        {
            max_xor<<=1;
            cur_try_max_xor=max_xor | 1;
            helper.clear();
            for (int j:nums)
                helper.insert(j>>i);
            for (int k:helper)
                if (helper.find(k^cur_try_max_xor)!=helper.end())
                {
                    max_xor=cur_try_max_xor;
                    break;
                }
        }
        return max_xor;
    }
};
