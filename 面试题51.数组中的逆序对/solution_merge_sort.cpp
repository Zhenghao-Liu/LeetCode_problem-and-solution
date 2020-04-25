class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int nums_size=nums.size();
        if (nums_size<2)
            return 0;
        vector<int> helper(nums_size);
        return merge(nums,helper,0,nums_size-1);
    }
    //操作的是nums[left]到nums[right]
    int merge(vector<int> &nums,vector<int> &helper,int left,int right)
    {
        if (left==right)
            return 0;
        //对当前长度为奇数时，左半部分比右半部分多一个元素
        //左半部分从nums[left]到nums[mid]
        //右半部分从nums[mid+1]到nums[right]
        int mid=left+((right-left)>>1);
        int left_ans=merge(nums,helper,left,mid);
        int right_ans=merge(nums,helper,mid+1,right);
        //倘若左边部分的末尾元素，小于，右半部分的第一个元素
        //即代表当前left~right是已经有序的了，就不需要再进行一次归并
        //最极端情况是只有两个元素，这时mid指向是左边的元素，所以不会越界
        if (nums.at(mid)<nums.at(mid+1))
            return left_ans+right_ans;
        int ans=merge_sort(nums,helper,left,mid,right);
        return left_ans+right_ans+ans;
    }
    int merge_sort(vector<int> &nums,vector<int> &helper,int left,int mid,int right)
    {
        for (int i=left;i<=right;++i)
            helper.at(i)=nums.at(i);
        int p_l=left,p_r=mid+1;
        int ans=0;
        for (int i=left;i<=right;++i)
        {
            //左边已经没有元素时，右边还有元素
            if (p_l==mid+1)
            {
                nums.at(i)=helper.at(p_r);
                ++p_r;
            }
            //左边还有元素，右边没有元素时
            //此时左边元素可以构成逆序对的个数已经在归并右边元素时统计过了，不要重复统计
            else if (p_r==right+1)
            {
                nums.at(i)=helper.at(p_l);
                ++p_l;
            }
            else if (helper.at(p_l)<=helper.at(p_r))
            {
                nums.at(i)=helper.at(p_l);
                ++p_l;
            }
            //else if (helper.at(p_l)>helper.at(p_r))
            else
            {
                nums.at(i)=helper.at(p_r);
                ++p_r;
                //倘若此时右边部分的[p_r]小于左边部分的[p_l]
                //表明[p_l]一直到[mid]都可以与[p_r]构成逆序对
                //所以第二个元素为[p_r]时的逆序对个数为mid-p_l+1
                ans+=mid-p_l+1;
            }
        }
        return ans;
    }
};
