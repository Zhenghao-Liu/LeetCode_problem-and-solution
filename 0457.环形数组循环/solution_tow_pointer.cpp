/*
* 采用快慢指针，如果重复代表出现环
* 注意题目说了nums[i]!=0
* 环有无可能长度为1
  那就通过判断slow的下一步是否还是slow
  如果slow的下一步还是slow说明该环长度为1，不可取
* 注意方向有正有负
  所以要记得取余后加上nums_size再取余，保证移动后的位置仍在合法范围0~nums_size-1之中
* 如何判断一个循环中不能同时向前向后
  可以采用nums[start]*nums[cur]>0来判断只要一个方向
  且nums[i]!=0所以不用考虑0的情况
* 如何剪枝
  已经走过的地方且无环那么下次就不用走了
  题目说了nums[i]!=0那么可以通过设0为标记已经走过了
  因为确定无环了，所以判定单个方向就可以为停止标记
  注意因为变为0，所以要提前缓存好起点
*/
class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int nums_size=nums.size();
        for (int i=0;i<nums_size;++i)
        {
            if (nums.at(i)==0)
                continue;
            int slow=i;
            int fast=get_next(nums,i,nums_size);
            while (nums.at(slow)!=0 && nums.at(fast)!=0 && nums.at(i)*nums.at(slow)>0 && nums.at(i)*nums.at(fast)>0 && nums.at(i)*nums.at(get_next(nums,fast,nums_size))>0)
            {
                if (slow==fast)
                {
                    if (get_next(nums,slow,nums_size)==slow)
                        break;
                    else
                        return true;
                }
                slow=get_next(nums,slow,nums_size);
                fast=get_next(nums,fast,nums_size);
                fast=get_next(nums,fast,nums_size);
            }
            slow=i;
            int start=nums.at(i);
            while (nums.at(slow)!=0 && nums.at(slow)*start>0)
            {
                int temp=slow;
                slow=get_next(nums,slow,nums_size);
                nums.at(temp)=0;
            }
        }
        return false;
    }
    int get_next(vector<int> &nums,int cur,const int &nums_size)
    {
        cur+=nums.at(cur);
        cur=(cur%nums_size+nums_size)%nums_size;
        return cur;
    }
};
