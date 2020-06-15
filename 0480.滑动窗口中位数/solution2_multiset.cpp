class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int nums_size=nums.size();
        multiset<int> window(nums.begin(),nums.begin()+k);
        //mid即是high_p
        multiset<int>::iterator mid=window.begin();
        for (int i=0;i<k/2;++i)
            ++mid;
        vector<double> ans;
        ans.reserve(nums_size-k+1);
        for (int i=k;;++i)
        {
            if (k%2==0)
            {
                multiset<int>::iterator low_p=prev(mid,1);
                ans.push_back(((double)*low_p+*mid)/2.0);
            }
            else
            {
                ans.push_back(*mid);
            }
            if (i==nums_size)
                break;
            window.insert(nums.at(i));
            if (nums.at(i)<*mid)
                --mid;
            if (nums.at(i-k)<=*mid)
                ++mid;
            window.erase(window.find(nums.at(i-k)));
        }
        return ans;
    }
};
