class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int nums_size=nums.size();
        vector<long long> sum(nums_size+1);
        sum.at(0)=0;
        for (int i=0;i<nums_size;++i)
            sum.at(i+1)=nums.at(i)+sum.at(i);
        return merge(sum,lower,upper,0,sum.size());
    }
    int merge(vector<long long>& sum,const int lower,const int upper,int start,int end)
    {
        if (end-start<=1)
            return 0;
        int mid=start+(end-start)/2;
        int left_part=merge(sum,lower,upper,start,mid);
        int right_part=merge(sum,lower,upper,mid,end);
        int result=merge_sort(sum,lower,upper,start,mid,end);
        return left_part+right_part+result;
    }
    int merge_sort(vector<long long>& sum,const int lower,const int upper,int start,int mid,int end)
    {
        int ans=0;
        int right_ans_begin=mid,right_ans_end=mid;
        for (int left_p=start;left_p<mid;++left_p)
        {
            while (right_ans_begin<end && sum.at(right_ans_begin)-sum.at(left_p)<lower)
                ++right_ans_begin;
            while (right_ans_end<end && sum.at(right_ans_end)-sum.at(left_p)<=upper)
                ++right_ans_end;
            ans+=(right_ans_end-right_ans_begin);
        }
        inplace_merge(sum.begin()+start,sum.begin()+mid,sum.begin()+end);
        return ans;
    }
};
