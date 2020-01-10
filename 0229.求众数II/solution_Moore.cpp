class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int nums_size=nums.size();
        int a,a_t,b,b_t;
        //设个初始值，只要不在数组中出现的即可
        a=b=5201314;
        a_t=b_t=0;
        for (int &i:nums)
        {
            if (i==a)
            {
                ++a_t;
                continue;
            }
            if (i==b)
            {
                ++b_t;
                continue;
            }
            if (a_t==0)
            {
                a=i;
                a_t=1;
                continue;
            }
            if (b_t==0)
            {
                b=i;
                b_t=1;
                continue;
            }
            --a_t;
            --b_t;
        }
        //上述是得出两个候选人，但求不出他们出现的次数，所以要再遍历一次
        a_t=b_t=0;
        for (int &i:nums)
            if (i==a)
                ++a_t;
            //因为有可能两个候选人是同一个，所以这里用else if
            else if (i==b)
                ++b_t;
        vector<int> answer;
        if (a_t>nums_size/3)
            answer.push_back(a);
        if (b_t>nums_size/3)
            answer.push_back(b);
        return answer;        
    }
};