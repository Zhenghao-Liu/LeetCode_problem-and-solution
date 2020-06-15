class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int nums_size=nums.size();
        deque<int> window;
        vector<double> ans;
        ans.reserve(nums_size-k+1);
        for (int i=0;i<k;++i)
        {
            deque<int>::iterator insert_p=upper_bound(window.begin(),window.end(),nums.at(i));
            window.insert(insert_p,nums.at(i));
        }
        if (k%2==0)
            ans.push_back(((double)window.at(k/2-1)+window.at(k/2))/2.0);
        else
            ans.push_back(window.at(k/2));
        for (int i=k;i<nums_size;++i)
        {
            deque<int>::iterator delete_p=lower_bound(window.begin(),window.end(),nums.at(i-k));
            window.erase(delete_p);
            deque<int>::iterator insert_p=upper_bound(window.begin(),window.end(),nums.at(i));
            window.insert(insert_p,nums.at(i));
            if (k%2==0)
                ans.push_back(((double)window.at(k/2-1)+window.at(k/2))/2.0);
            else
                ans.push_back(window.at(k/2));
        }
        return ans;
    }
};
