class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int nums_size=nums.size();
        if (nums_size==0)
            return {};
        vector<int> answer(nums_size-k+1);
        for (int i=0;i<=nums_size-k;++i)
        {
            int max=INT_MIN;
            for (int j=0;j<k;++j)
                if (nums.at(i+j)>max)
                    max=nums.at(i+j);
            answer.at(i)=max;
        }
        return answer;
    }
};
