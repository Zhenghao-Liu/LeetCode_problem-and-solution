class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        vector<int> ans;
        int nums_size=nums.size();
        for (int i=0;i<nums_size;++i)
            if (nums.at(i)==1)
                ans.push_back(i);
        int ans_size=ans.size();
        if (ans.size()==0)
            return true;
        int left=ans.at(0);
        for (int i=1;i<ans_size;++i)
            if (ans.at(i)-left-1>=k)
                left=ans.at(i);
            else
                return false;
        return true;
    }
};
