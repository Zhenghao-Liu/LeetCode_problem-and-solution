class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int T_size=T.size();
        stack<int> helper;
        vector<int> ans(T_size,0);
        for (int i=T_size-1;i>=0;--i)
        {
            while (!helper.empty() && T.at(i)>=T.at(helper.top()))
                helper.pop();
            if (!helper.empty())
                ans.at(i)=helper.top()-i;
            helper.push(i);
        }
        return ans;
    }
};
