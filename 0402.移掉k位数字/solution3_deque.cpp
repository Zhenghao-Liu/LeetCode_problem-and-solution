//单调栈；对于a b c ··· 倘若b<a 则a没有存在意义删除a
class Solution {
public:
    string removeKdigits(string num, int k) {
        int num_size=num.size();
        int ans_size=num_size-k;
        if (ans_size==0)
            return "0";
        deque<char> helper;
        for (int i=0;i<num_size;++i)
        {
            while (!helper.empty() && ans_size-helper.size()<num_size-i && num.at(i)<helper.back())
                helper.pop_back();
            if (helper.size()+1<=ans_size)
                helper.push_back(num.at(i));
        }
        string ans;
        while (!helper.empty())
        {
            if (!(ans.empty() && helper.front()=='0'))
                ans+=helper.front();
            helper.pop_front();
        }
        return ans.empty() ? "0" : ans;
    }
};
