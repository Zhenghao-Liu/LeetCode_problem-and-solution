class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int before=INT_MIN/2;
        int nums_size=nums.size();
        for (int i=0;i<nums_size;++i)
            if (nums.at(i)==1)
            {
                if (i-before-1>=k)
                    before=i;
                else
                    return false;
            }
        return true;
    }
};
