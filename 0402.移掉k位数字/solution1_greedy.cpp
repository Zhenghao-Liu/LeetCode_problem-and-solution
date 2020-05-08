class Solution {
public:
    string removeKdigits(string num, int k) {
        int num_size=num.size();
        int ans_size=num_size-k;
        //[start,end]
        int start=0,end=k;
        string ans;
        while (end<num_size)
        {
            char min='9'+1;
            int min_pos=-1;
            for (int i=start;i<=end;++i)
                if (num.at(i)<min)
                {
                    min=num.at(i);
                    min_pos=i;
                }
            //注意前导0
            if (!(ans.empty() && min=='0'))
                ans+=min;
            start=min_pos+1;
            ++end;
        }
        return ans.empty() ? "0" : ans;
    }
};
