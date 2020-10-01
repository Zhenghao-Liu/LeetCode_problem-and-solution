class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int T_size=T.size();
        stack<int> helper;
        vector<int> ans(T_size,0);
        for (int i=0;i<T_size;++i)
        {
            while (!helper.empty() && T.at(i)>T.at(helper.top()))
            {
                ans.at(helper.top())=i-helper.top();
                helper.pop();
            }
            helper.push(i);
        }
        return ans;
    }
};
