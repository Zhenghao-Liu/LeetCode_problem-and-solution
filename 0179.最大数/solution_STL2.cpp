//进一步优化排序效率
class Solution {
public:
    static bool cmp(const string &a,const string &b)
    {
        int a_size=a.size(),b_size=b.size(),min_size=min(a_size,b_size);
        for (int i=0;i<min_size;++i)
            if (a.at(i)!=b.at(i))
                return a.at(i)>b.at(i);
        for (int i=min_size;i<a_size;++i)
            if (b.at(0)!=a.at(i))
                return a.at(i)>b.at(0);
        for (int i=min_size;i<b_size;++i)
            if (a.at(0)!=b.at(i))
                return a.at(0)>b.at(i);
        return (a+b)>(b+a);
    }
    string largestNumber(vector<int>& nums) {
        int nums_size=nums.size();
        if (nums_size==0)
            return "0";
        bool judge_zero=true;
        vector<string>nums_s;
        for (int &i:nums)
        {
            if (i!=0 && judge_zero)
                judge_zero=false;
            nums_s.push_back(to_string(i));
        }
        if (judge_zero)
            return "0";
        sort(nums_s.begin(),nums_s.end(),cmp);
        string answer="";
        for (string &i:nums_s)
            answer.append(i);
        return answer;
    }
};
