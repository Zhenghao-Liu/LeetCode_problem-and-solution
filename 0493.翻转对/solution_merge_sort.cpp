class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int nums_size=nums.size();
        vector<int> temp(nums_size);
        return merge(nums,temp,0,nums_size-1);
    }
    //left:[start,mid] right:[mid+1,right]
    int merge(vector<int> &nums,vector<int> &temp,int start,int end)
    {
        if (start>=end)
            return 0;
        int mid=start+(end-start)/2;
        int left=merge(nums,temp,start,mid);
        int right=merge(nums,temp,mid+1,end);
        int cur=0;
        int j=mid+1;
        //先暴力求翻转对之后再归并
        for (int i=start;i<=mid;++i)
        {
            while (j<=end && nums.at(j)*(long long)2<nums.at(i))
                ++j;
            cur+=j-(mid+1);
        }
        merge_sort(nums,temp,start,mid,end);
        return left+right+cur;
    }
    void merge_sort(vector<int> &nums,vector<int> &temp,int start,int mid,int end)
    {
        for (int i=start;i<=end;++i)
            temp.at(i)=nums.at(i);
        int i=start,j=mid+1;
        int index=start;
        while (i<=mid || j<=end)
        {
            if (i==mid+1)
            {
                nums.at(index)=temp.at(j);
                ++j;
            }
            else if (j==end+1)
            {
                nums.at(index)=temp.at(i);
                ++i;
            }
            else if (temp.at(i)<=temp.at(j))
            {
                nums.at(index)=temp.at(i);
                ++i;
            }
            else if (temp.at(i)>temp.at(j))
            {
                nums.at(index)=temp.at(j);
                ++j;
            }
            ++index;
        }
    }
};
