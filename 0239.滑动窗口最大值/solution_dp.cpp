class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int nums_size=nums.size();
        if (nums_size==0)
            return {};
        vector<int> left(nums_size);
        for (int i=0;i<nums_size;i=i+k)
        {
            left.at(i)=nums.at(i);
            for (int j=i+1;j<nums_size && j-i<k;++j)
                left.at(j)=max(left.at(j-1),nums.at(j));
        }
        vector<int> right(nums_size);
        for (int i=0;i<nums_size;i=i+k)
        {
            int j;
            if (i+k-1<nums_size)
                j=i+k-1;
            else
                j=nums_size-1;
            right.at(j)=nums.at(j);
            for (--j;j>=i;--j)
                right.at(j)=max(right.at(j+1),nums.at(j));
        }
        vector<int> answer(nums_size-k+1);
        int index=0;
        for (int i=0;i+k-1<nums_size;++i)
        {
            answer.at(index)=max(left.at(i+k-1),right.at(i));
            ++index;
        }
        return answer;
    }
};
