class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int sz=nums.size();
        int s=0,f=0;
        while (f<sz) {
            if (nums.at(f)==val) {
                f++;
            } else {
                nums.at(s)=nums.at(f);
                s++;
                f++;
            }
        }
        return s;
    }
};