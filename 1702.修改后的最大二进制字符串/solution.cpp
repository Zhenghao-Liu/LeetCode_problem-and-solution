/*
 * 00->10
   10->01
 * 00->10能使字符串变大，所以遇到00一定是全都变成10
 * 10->01会使这两个数字变的小，是否要变呢？能变大的数字是00，现在10->01往前面凑了个0，只要前面还有0就可以变
   不是要求紧凑的0，即010这种紧凑的才可以变，01111110前面出现有0就可以变，因为10->01，即可以看成10往前挪了，一直递归到0那个位置出现00为止结束递归
   所以也是O(1)的修改，即0 1 ····(n个全是1) 0 ，会被修改成 1 0  ···(n个全是1) 1
 * 所以需要一个变量记录前面有无1，加上前面O(1)修改，只用记录最后一个0出现的位置即可
 */
class Solution {
public:
    string maximumBinaryString(string binary) {
        string ans;
        int size=binary.size();
        int zero=-1;
        for (int i=0;i<size;i++) {
            char ii=binary.at(i);
            ans+=ii;
            if (ii=='0' && i-1>=0 && ans.at(i-1)=='0') {
                ans.at(i-1)='1';
                zero=i;
            } else if (ii=='0' && i-1>=0 && ans.at(i-1)=='1' && zero!=-1) {
                ans.at(zero)='1';
                ans.at(zero+1)='0';
                ans.at(i)='1';
                zero=zero+1;
            }
            if (zero==-1) {
                zero= ans.back()=='0' ? i : -1;
            }
        }
        return ans;
    }
};
