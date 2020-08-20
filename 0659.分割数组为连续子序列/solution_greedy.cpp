/*
* 一个数字要想构成连续序列，有两种可能
  1. 找到前面已经连续的序列，将当前数字加在末尾
  2. 以自己为新序列的起始，因为每个子序列至少要长度为3，所以要向后找两个元素以构成连续子序列
* 贪心：
  1. 倘若该数字能往后找到有两个元素能构成序列，且又有前面已经连接的序列，那么这两个序列可以直接连在一起成为一个长序列，那么按照可能1的策略即可实现连成一个较长的序列，没必要新开一个序列
  2. 为什么只用找到向后两个元素，而不是有多长找多长呢，eg[1 2 3 3 4 5]倘若1向后找到了2、3、4、5，那么3就没有选择了，只用找后两个是给别的元素留有更多的机会，反正还有可能1会构成长长的序列。
*/
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> count;
        for (int i:nums)
            ++count[i];
        unordered_map<int,int> nums_end_count;
        for (int i:nums)
        {
            if (count.at(i)<=0)
                continue;
            --count.at(i);
            if (nums_end_count.find(i-1)!=nums_end_count.end() && nums_end_count.at(i-1)>0)
            {
                --nums_end_count.at(i-1);
                ++nums_end_count[i];
            }
            else if (count.find(i+1)!=count.end() && count.at(i+1)>0 && count.find(i+2)!=count.end() && count.at(i+2)>0)
            {
                --count.at(i+1);
                --count.at(i+2);
                ++nums_end_count[i+2];
            }
            else
                return false;
        }
        return true;
    }
};
