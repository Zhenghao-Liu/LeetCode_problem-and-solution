/*
* 将nums排序，那左边是较小一边放在奇数位，右边是较大一边，放在偶数位
* 注意[1,2,2,3]这种中间部分是有重复数字的例子
* 倘若左右部分正序来放的话，是[1,2,2,3]就会出现等于的情况
* 所以左右部分采取倒序的方法来放，即左[1,2]按照[2,1]放,右边[2,3]按照[3,2]放
* 结果就是[2,3,1,2]
* 复杂度O(Nlogn) 空间复杂度O(N)
*/
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> v(nums);
        sort(v.begin(),v.end());
        int nums_size=nums.size();
        int judge=1;
        int p_l=(nums_size-1)/2,p_r=nums_size-1;
        for (int i=0;i<nums_size;++i)
        {
            if (judge)
            {
                nums.at(i)=v.at(p_l);
                --p_l;
            }
            else
            {
                nums.at(i)=v.at(p_r);
                --p_r;
            }
            judge^=1;
        }
    }
};
