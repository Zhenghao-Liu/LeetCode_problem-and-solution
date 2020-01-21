class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int nums_size=nums.size();
        if (nums_size==0)
            return {};
        multiset<int,greater<int>> window;
        for (int i=0;i<k;++i)
            window.insert(nums.at(i));
        vector<int> answer;
        answer.push_back(*window.begin());
        for (int i=k;i<nums_size;++i)
        {
            window.insert(nums.at(i));
            window.erase(window.find(nums.at(i-k)));
            answer.push_back(*window.begin());
        }
        return answer;
    }
};
