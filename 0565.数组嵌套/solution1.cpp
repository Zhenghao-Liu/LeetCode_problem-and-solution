/*
* 注意题目给的数据范围：
  1. nums中不含有重复的元素
  2. nums中元素大小在[0,N-1]之间(N是nums数组大小)
* 显然无论哪个元素自身哈希都一定会有环的出现
* 那么只需要走一遍环即可判断最长环的长度
* 但是同一个环里面所有元素为起点的话，他们走的都是同一个环，自然这个环的长度也是一样的
  所以通过use判别有没有走过该点来防止走重复的环
*/
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int nums_size=nums.size();
        int ans=1;
        vector<bool> use(nums_size,false);
        for (int i=0;i<nums_size;++i)
            if (!use.at(i))
            {
                int cur=1;
                int begin=nums.at(i);
                int j=nums.at(begin);
                use.at(begin)=true;
                while (j!=begin)
                {
                    use.at(j)=true;
                    j=nums.at(j);
                    ++cur;
                }
                ans=max(ans,cur);
            }
        return ans;
    }
};
