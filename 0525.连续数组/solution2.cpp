//和法一一样，但是开数组存pos，因为最坏情况是全为1或全为0，所以数组长度为size*2+1，且[i]这个i=prefix+size
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int nums_size=nums.size();
        vector<int> pos(nums_size*2+1,-2);
        int prefix=0;
        pos.at(0+nums_size)=-1;
        int ans=0;
        for (int i=0;i<nums_size;++i)
        {
            if (nums.at(i)==1)
                prefix+=1;
            else
                prefix+=-1;
            if (pos.at(prefix+nums_size)==-2)
                pos.at(prefix+nums_size)=i;
            else
                ans=max(ans,i-pos.at(prefix+nums_size));
        }
        return ans;
    }
};
