//将奇数设为1，用负数形式来统计奇数之间有几个偶数
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int nums_size=nums.size();
        vector<int> p_m_index;
        int count=0;
        for (int i=0;i<nums_size;++i)
            //奇数
            if ((nums.at(i)&1)==1)
            {
                p_m_index.push_back(count);
                count=0;
                p_m_index.push_back(1);
            }
            //偶数
            else
                --count;
        if ((nums.back() & 1)==1)
            p_m_index.push_back(0);
        else
            p_m_index.push_back(count);
        if ((p_m_index.size()-1)/2<k)
            return 0;
        int ans=0;
        int left_p=1,right_p=(k-1)*2+left_p;
        int p_m_index_size=p_m_index.size();
        while (right_p<p_m_index_size)
        {
            ans+=(-1+p_m_index.at(left_p-1))*(-1+p_m_index.at(right_p+1));
            left_p+=2;
            right_p+=2;
        }
        return ans;
    }
};
