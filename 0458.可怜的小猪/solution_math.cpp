/**
* 一只猪状态数量state=minutesToTest/minutesToDie+1
  eg：假设可以喝3次水即minutesToTest/minutesToDie=3
  那状态只有：喝完一次死，喝完两次死，喝完三次死，喝完三次后存活，4种状态
* 在状态数量只有2时，x只猪可以测2^x个桶
  二进制来处理，若两只猪可以列一个二维的矩阵，若三只猪那么可以通过列三维的矩阵来说明
  eg：1只猪时，要么一死要么活，就只可以测2个桶
  2只猪时，二进制有00 01 10 11，即桶1两只猪都不喝，桶2猪2喝，桶3猪1喝，桶4猪1猪2喝，就可以4种情况独立
  3只猪时，同样二进制分配即可
* x只猪时s状态数量，可以测s^x个桶
  eg：无论多少只猪，状态数量为1即只有存活即不喝时，只能检测1个桶，即1^x个桶
  x只猪，状态数量为2则可以测2^x个桶
  x只猪，状态数量为3则可以测3^x个桶，其实是3进制
  eg 2只猪，状态数量为3则
     桶1 00
     桶2 01
     桶3 02
     桶4 10
     桶5 11
     桶6 12
     桶7 20
     桶8 21
     桶9 22
    举例 桶8代表猪1在第二次时候喝，且猪2在第一次时候喝
         桶3表猪2在第二次时候喝
* 因此只要s^x>=bucket即可
  即x>=log(bucket)/log(s)
  且x是正整数，所以要向上取整
*/
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int state=minutesToTest/minutesToDie+1;
        return ceil(log(buckets)/log(state));
    }
};
