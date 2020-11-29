//odd 奇数
class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int size=nums.size();
        vector<int> odd_lr(size);
        vector<int> odd_rl(size);
        vector<int> even_lr(size);
        vector<int> even_rl(size);
        for (int i=1;i<size;++i)
        {
            odd_lr.at(i)=odd_lr.at(i-1);
            even_lr.at(i)=even_lr.at(i-1);
            if ((i-1)%2==0)
                even_lr.at(i)+=nums.at(i-1);
            else
                odd_lr.at(i)+=nums.at(i-1);
        }
        for (int i=size-2;i>=0;--i)
        {
            odd_rl.at(i)=odd_rl.at(i+1);
            even_rl.at(i)=even_rl.at(i+1);
            if ((i+1)%2==0)
                even_rl.at(i)+=nums.at(i+1);
            else
                odd_rl.at(i)+=nums.at(i+1);
        }
        int ans=0;
        for (int i=0;i<size;++i)
        {
            int odd= odd_lr.at(i)+even_rl.at(i);
            int even= even_lr.at(i)+odd_rl.at(i);
            if (odd==even)
                ++ans;
        }
        return ans;
    }
};
