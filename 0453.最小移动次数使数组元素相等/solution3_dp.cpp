/*
* 先排好序
* dp思想
* eg[1 2 4 6]
* 一开始只考虑[1 2]
  那只需要1次就是把[0]=1变成[0]=2就好了
  但是这里加一不但影响[0]，还会影响到[2]=4 [3]=6
  即操作前面的同时，后面的元素都会受到影响，即移动一步后面都应该加1
* 所以移动后应该是[2 2 5 7]
  但是这样复杂度过高了
  可以采用单个元素加上目前总移动步数
  即[1 2 4 6]差值为1，本次要移动1，总步数1，那么[2]+1即[2 2 5 6]
* [2 2 5 6]差值为3，本次移动为3，总步数4，那么[3]+4即[5 5 5 10]
* 最后一次移动为5，即总步数9
*/
class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
        int nums_size=nums.size();
        for (int i=1;i<nums_size;++i)
        {
            int diff=nums.at(i)-nums.at(i-1);
            ans+=diff;
            if (i+1<nums_size)
                nums.at(i+1)+=ans;
        }
        return ans;
    }
};
