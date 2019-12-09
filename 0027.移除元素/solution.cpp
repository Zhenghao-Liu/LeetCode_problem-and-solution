class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int length=nums.size(),begin_p=0;
        int end_p=length-1,judge=0;
        sort(nums.begin(),nums.end());
        for (int i=0;i<length;++i)
            if (nums.at(i)==val)
            {
                begin_p=i;
                judge=1;
                break;
            }
        if (judge==0)
            return length;
        for (int i=begin_p+1;i<length;++i)
            if (nums.at(i)!=val)
            {
                end_p=i-1;
                break;
            }
        int delete_length=end_p-begin_p+1;
        for (int i=begin_p;(i+delete_length)<length;++i)
            nums.at(i)=nums.at(i+delete_length);
        return (length-delete_length);        
    }
};
