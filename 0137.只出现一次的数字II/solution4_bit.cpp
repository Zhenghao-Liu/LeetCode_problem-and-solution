//不建议使用
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int nums_size=nums.size();
        sort(nums.begin(),nums.end());
        int d=nums.at(0),a,b,c;
        for (int i=1;i<nums_size-2;i=i+3)
        {
            a=nums.at(i),b=nums.at(i+1),c=nums.at(i+2);
            d=(b&(~c)&(~d))|((~a)&(~c)&d)|(a&b&c&d)|((~b)&c&(~d))|(a&(~b)&(~c));
        }
        return d;
    }
};
