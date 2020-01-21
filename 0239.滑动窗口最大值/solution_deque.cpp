class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> window;
        int nums_size=nums.size();
        if (nums_size==0)
            return {};
        for (int i=0;i<k;++i)
        {
            while (!window.empty() && nums.at(i)>window.back())
                window.pop_back();
            window.push_back(nums.at(i));
        }
        vector<int> answer(nums_size-k+1);
        answer.at(0)=window.front();
        int index=1;
        for (int i=k;i<nums_size;++i)
        {
            if (nums.at(i-k)==window.front())
                window.pop_front();
            while (!window.empty() && nums.at(i)>window.back())
                window.pop_back();
            window.push_back(nums.at(i));
            answer.at(index)=window.front();
            ++index;
        }
        return answer;
    }
};
