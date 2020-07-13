/*
* 要想0和1出现的次数相同，可以把0当成-1的，把1还是1，然后通过前缀和sum[j]-sum[i]=0求出一段区间是否是0和1出现次数相同
* 用pos[前缀和]=第一次出现该前缀和的位置，来求尽可能的长的子数组
*/
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int nums_size=nums.size();
        unordered_map<int,int> pos;
        int prefix=0;
        pos.insert({0,-1});
        int ans=0;
        for (int i=0;i<nums_size;++i)
        {
            if (nums.at(i)==1)
                prefix+=1;
            else
                prefix+=-1;
            if (pos.find(prefix)==pos.end())
                pos.insert({prefix,i});
            else
                ans=max(ans,i-pos.at(prefix));
        }
        return ans;
    }
};
