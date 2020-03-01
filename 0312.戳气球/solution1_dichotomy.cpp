/*
* 二分法
* 我们设helper(i,j)为处理从[i,j]即戳破i到j所有气球包括i和j
  设中间元素为k，即i···k···j,那对于k左边区间金币值是helper(i,k-1)，右边是helper(k+1,j)
  问题来了。既然我们要戳破k，那么对于helper(i,k-1)、helper(k+1,j)气球之间的相邻关系是有变化的
  这就不符合二分法的原则：分开的两部分应该之间是互不影响的
* 所以要换一种分的方法来让两部分不影响
* 我们设helper(i,j)为处理从(i,j)即戳破i到j所有气球,但是不包括i和j
  这样的话对于helper(i,j)处理i···k···j，细分一点是i i+1···k-1 k k+1···j-1 j，
  处理的是[i+1,k-1]+[k+1,j-1]+nums[i]*nums[j]*nums[k]，因为以k为中间，删完两边后就只剩i j k，就只需要删除k即可了
* 详细一点动态方程helper(i,j)=max(helper(i,k)+helper(k,j)+nums[i]*nums[j]*nums[k]) k属于(i,j)，求最大值
* 注意k有可能不存在，就是i=j+1的情况，这时候由于中间没有元素删除了，所以helper(i,i+1)=0
* 我们只需要在原有数组的基础上左右加上一个1，就可以刚好匹配helper(i,j)
*/
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int nums_size=nums.size();
        if (nums_size==0)
            return 0;
        vector<int> nums_m(nums_size+2);
        nums_m.at(0)=1;
        nums_m.at(nums_size+1)=1;
        for (int i=0;i<nums_size;++i)
            nums_m.at(i+1)=nums.at(i);
        vector<vector<int>> cache(nums_size+2,vector<int>(nums_size+2,0));
        return helper(nums_m,0,nums_size+1,cache);
    }
    int helper(vector<int> & nums_m,int begin,int end,vector<vector<int>> & cache)
    {
        if (begin+1==end)
            return 0;
        if (cache.at(begin).at(end)!=0)
            return cache.at(begin).at(end);
        int answer=0;
        int result=nums_m.at(begin)*nums_m.at(end);
        for (int i=begin+1;i<end;++i)
        {
            int temp=helper(nums_m,begin,i,cache)+helper(nums_m,i,end,cache)+result*nums_m.at(i);
            if (temp>answer)
                answer=temp;
        }
        cache.at(begin).at(end)=answer;
        return answer;
    }
};
